#include <MQTTClient.h>

#define ADDRESS     "tcp://MQTTBroker2.us-west-1.elasticbeanstalk.com:1883"
#define CLIENTID    "ExampleClientSub"
#define QOS         1
#define TIMEOUT     10000L
volatile MQTTClient_deliveryToken deliveredtoken;

#include <time.h>
#include <sys/time.h>
#include <unistd.h>

typedef void (*mqtt_delivered)(void *context, MQTTClient_deliveryToken dt);
typedef int (*mqtt_msgarrvd)(void *context, char *topicName, int topicLen, MQTTClient_message *message);
typedef void (*mqtt_connlost)(void *context, char *cause);

int mqtt_subscribe(void *context, mqtt_delivered, mqtt_msgarrvd, mqtt_connlost);
