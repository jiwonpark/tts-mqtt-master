/*
 * tts-mqtt-test.c
 *
 *  Created on: Aug 6, 2018
 *      Author: jiwon
 */

#include <tizen.h>
#include <service_app.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <MQTTClient.h>

#define ADDRESS     "tcp://MQTTBroker2.us-west-1.elasticbeanstalk.com:1883"
#define CLIENTID    "ExampleClientSub"
#define QOS         1
#define TIMEOUT     10000L
volatile MQTTClient_deliveryToken deliveredtoken;

#include "log.h"

static void _delivered(void *context, MQTTClient_deliveryToken dt)
{
    DBG("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

static int __msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
	DBG("Message arrived");
    DBG("     topic: %s", topicName);

    char msg_str[1000];
    strncpy(msg_str, message->payload, message->payloadlen);
    msg_str[message->payloadlen] = '\0';
    DBG("   message: \"%s\"", msg_str);

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

static void __connlost(void *context, char *cause)
{
    DBG("Connection lost\n");
    DBG("     cause: %s\n", cause);
}

static bool service_app_create(void *user_data)
{
	DBG("service_app_create");

	MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;

    char client_id[500];
    sprintf(client_id, "%s-%d", CLIENTID, rand() % 100000);

    MQTTClient_create(&client, ADDRESS, client_id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client, NULL, __connlost, __msgarrvd, _delivered);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        DBG("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    const char* topic = "/some/topic/name";
    DBG("Subscribing to topic %s for client %s using QoS%d\n", topic, client_id, QOS);
    MQTTClient_subscribe(client, topic, QOS);

//    MQTTClientDBGisconnect(client, 10000);
//    MQTTClientDBGestroy(&client);
    return true;
}

static void service_app_terminate(void *user_data)
{
	DBG("service_app_terminate");
}

static void service_app_control(app_control_h app_control, void *user_data)
{
	DBG("service_app_control");

	if (app_control == NULL) {
		ERR("app_control is NULL");
		return;
	}
}

int main(int argc, char *argv[])
{
	char ad[50] = {0,};
	service_app_lifecycle_callback_s event_callback;

	event_callback.create = service_app_create;
	event_callback.terminate = service_app_terminate;
	event_callback.app_control = service_app_control;

	return service_app_main(argc, argv, &event_callback, ad);
}
