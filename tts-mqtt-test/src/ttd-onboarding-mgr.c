//#include "ttd-http.h"
//#include <curl/curl.h>
//
//#include <glib.h>
//#include <glib/gi18n.h>

//#include <yaca/yaca_sign.h>
//#include <yaca/yaca_digest.h>

#include <stdio.h>
#include <string.h>

//#include "ttd-onboarding-mgr.h"

//#include <json.h>
#include "ttd-log.h"

#include "ttd-mqtt-mgr.h"

//#define ONBOARDING_API_URL "http://ttswebserver-test-jiwon.us-west-1.elasticbeanstalk.com/api/onboarding"

//extern int __ttd_http_post2(const char *url,
//	const char *msg_body, struct curl_slist *headers, char **json_data, long *res_code);
//
//extern int __ttd_http_put(const char *url,
//	const char *msg_body, struct curl_slist *headers, char **json_data, long *res_code);

//static char* __trim_priv(const char *pem_priv);
//static char* __trim_pub(const char *pem_pub);
//static char* __concat(const char *multiline_str);

//typedef struct {
//	char *pin;
//    char* device_id;
////    char* private_key;
//    char* public_key_base64;
//} Onboarding;
//
//static void __delivered(void *context, MQTTClient_deliveryToken dt);
//static int __msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);
//static void __connlost(void *context, char *cause);

//#include <ckmc/ckmc-manager.h>

#include <stdlib.h>

void ttd_onboarding_test()
{
//	Onboarding* onboarding = (Onboarding*)calloc(1, sizeof(Onboarding)); // calloc initializes memory to 0

//	ttd_http_init();
//
//	ttd_onboarding_start(&onboarding->pin);
//
//	ttd_onboarding_register_device_id(onboarding->pin, onboarding->device_id);

//	mqtt_subscribe(onboarding, __delivered, __msgarrvd, __connlost);
}

//void ttd_onboarding_test_1()
//{
//	Onboarding* onboarding = (Onboarding*)calloc(1, sizeof(Onboarding)); // calloc initializes memory to 0
//
//	ttd_http_init();
//
//	const char *pin;
//	const char *device_id;
//
//	ttd_onboarding_register_device_id(pin, device_id);
//
//	ttd_onboarding_generate_key_pair(&onboarding->private_key, &onboarding->public_key);
//
//	__concat(__trim_priv(onboarding->private_key));
////	__concat(__trim_pub(onboarding->public_key));
//
//	const char *trimmed = __trim_pub(onboarding->public_key);
//	const char *public_key_togo = __concat(trimmed);
//
////	ttd_onboarding_register_public_key("FAHMJH", public_key_togo);
//
//	char* sign = NULL;
//	ttd_onboarding_sign(&sign, onboarding->private_key, "attack at dawn");
//}

//int ttd_onboarding_start(char **pin)
//{
//	_D("hi!\n");
//
//	struct curl_slist *headers = NULL;
//	headers = curl_slist_append(headers, "Accept: application/json");
//	headers = curl_slist_append(headers, "Content-Type: application/json");
//	long res_code;
//	char* data = NULL;
//	int ret =
//		__ttd_http_post2(ONBOARDING_API_URL,
//		                 "{\"device\":\"ddddffff\"}", headers, &data, &res_code);
//
//	json_object* root_obj = json_tokener_parse(data);
//	if (!root_obj) {
//		_E("Body is not json");
//		return -1;
//	}
//
//	json_object* pin_obj = json_object_object_get(root_obj, "pin");
//	if (!pin_obj) {
//		_E("No pin");
//		return -1;
//	}
//
//	*pin = strdup(json_object_get_string(pin_obj));
//
//	_D("here %d %ld %s %s\n", ret, res_code, data, *pin);
//
//	_D("bye!\n");
//
//	return 0;
//}
//
//int ttd_onboarding_register_device_id(const char *pin, const char *device_id)
//{
////	_D("hi!\n");
////
////	struct curl_slist *headers = NULL;
////	headers = curl_slist_append(headers, "Accept: application/json");
////	headers = curl_slist_append(headers, "Content-Type: application/json");
////	long res_code;
////	char* data = NULL;
////	int ret =
////		__ttd_http_post2(ONBOARDING_API_URL,
////		                 "{\"device\":\"ddddffff\"}", headers, &data, &res_code);
////
////	json_object* root_obj = json_tokener_parse(data);
////	if (!root_obj) {
////		_E("Body is not json");
////		return -1;
////	}
////
////	json_object* pin_obj = json_object_object_get(root_obj, "pin");
////	if (!pin_obj) {
////		_E("No pin");
////		return -1;
////	}
////
////	pin = json_object_get_string(pin_obj);
////
////	_D("here %d %ld %s %s\n", ret, res_code, data, pin);
////
////	mqtt_subscribe();
////
////	_D("bye!\n");
////
//	return 0;
//}

//static void __delivered(void *context, MQTTClient_deliveryToken dt)
//{
//    _D("Message with token value %d delivery confirmed\n", dt);
//    deliveredtoken = dt;
//}
//
//static int __msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
//{
//	_D("Message arrived\n");
//    _D("     topic: %s\n", topicName);
//
//    char msg_str[1000];
//    strncpy(msg_str, message->payload, message->payloadlen);
//    msg_str[message->payloadlen] = '\0';
//    _D("   message: \"%s\"", msg_str); // "onboarding.user-auth"
//
//    if (strcmp(msg_str, "onboarding.user-auth") == 0) {
//
//    	_D("CONTINUE ONBOARDING!");
//
////    	Onboarding* onboarding = (Onboarding *)context;
//
////    	ttd_onboarding_generate_key_pair("PRV_RSA1", &onboarding->public_key_base64);
//
//    	_D("KEY GENERATED SUCCESSFULLY!");
//
////    	ttd_onboarding_register_public_key(onboarding->pin, onboarding->public_key_base64);
//
////    	char* sign = NULL;
////    	ttd_onboarding_sign(&sign, "PRV_RSA1", "attack at dawn");
//    }
//
//    MQTTClient_freeMessage(&message);
//    MQTTClient_free(topicName);
//    return 1;
//}
//
//static void __connlost(void *context, char *cause)
//{
//    _D("\nConnection lost\n");
//    _D("     cause: %s\n", cause);
//}

//int ttd_onboarding_generate_key_pair(const char *private_key_alias, char **public_key_base64)
//{
//	{
//		int ret = CKMC_ERROR_NONE;
//
//		size_t size = 2048; // Key Manager supports 1024, 2048, 4096
////		const char *private_key_alias = "PRV_RSA1";
//		const char *public_key_alias = "PUB_RSA1";
//		ckmc_policy_s policy_private_key;
//		ckmc_policy_s policy_public_key;
//
//		// This private key is encrypted with an additional password
//		policy_private_key.password = NULL;
//		policy_private_key.extractable = true; // This key cannot be extracted from the key manager
//
//		policy_public_key.password = NULL;
//		policy_public_key.extractable = true;
//
//		ret = ckmc_create_key_pair_rsa(size, private_key_alias, public_key_alias, policy_private_key, policy_public_key);
//		if (CKMC_ERROR_NONE != ret)
//		{
//		   // Error handling
//		}
//	}
//
//	{
//		int ret = CKMC_ERROR_NONE;
//
//		ckmc_alias_list_s *alias_list;
////		ckmc_alias_list_s *plist;
//		ckmc_key_s *test_key;
////		char* key_password = NULL;
////		int count_list = 0;
//
//		ret = ckmc_get_key_alias_list(&alias_list);
//		if (CKMC_ERROR_NONE != ret)
//		{
//		   // Error handling
//		}
//
//	   ckmc_get_key("PUB_RSA1", NULL, &test_key);
//       char* base64_key_pub = g_base64_encode(test_key->raw_key, test_key->key_size);
////		_D("%d %s", test_key->key_size, test_key->raw_key);
//	   ckmc_key_free(test_key);
//
//	   *public_key_base64 = base64_key_pub;
//		_D("%s", *public_key_base64);
//
////	   ckmc_get_key("PRV_RSA1", NULL, &test_key);
////       const char* base64_key_prv = g_base64_encode(test_key->raw_key, test_key->key_size);
//////		_D("%d %s", test_key->key_size, test_key->raw_key);
////		_D("%s", base64_key_prv);
////	   ckmc_key_free(test_key);
//
////		plist = alias_list;
////		do
////		{
////		   ckmc_get_key(plist->alias, key_password, &test_key);
//////		   dlog_print(DLOG_INFO, LOG_TAG, "%d th key : key size =%d\n", ++count_list, test_key->key_size);
////			_D("%s %d %s", plist->alias, test_key->key_size, test_key->raw_key);
////		   ckmc_key_free(test_key);
////		   plist = plist->next;
////		}
////		while(plist != NULL);
//
//		ckmc_alias_list_all_free(alias_list); // Called when the list is no longer needed.
//	}
//
//	return 0;
//}
//
//int ttd_onboarding_register_public_key(const char *pin, const char *public_key_base64)
//{
//	_D("hi!\n");
//
//	char buffer[1000];
//	sprintf(buffer, "{\"pin\":\"%s\",\"key\":\"%s\"}", pin, public_key_base64);
//
//	struct curl_slist *headers = NULL;
//	headers = curl_slist_append(headers, "Accept: application/json");
//	headers = curl_slist_append(headers, "Content-Type: application/json");
//	long res_code;
//	char* data = NULL;
//	int ret = __ttd_http_post2(ONBOARDING_API_URL"/device", buffer, headers, &data, &res_code);
//
////	json_object* root_obj = json_tokener_parse(data);
////	if (!root_obj) {
////		_E("Body is not json");
////		return -1;
////	}
////
////	json_object* pin_obj = json_object_object_get(root_obj, "pin");
////	if (!pin_obj) {
////		_E("No pin");
////		return -1;
////	}
////
////	_D("here %d %ld %s %s\n", ret, res_code, data, pin);
//
//	_D("here %d %ld\n", ret, res_code);
//
//	_D("bye!\n");
//
//	return 0;
//}
//
//int ttd_onboarding_sign(char **sign, const char *private_key_alias, const char *data)
//{
//	int ret = CKMC_ERROR_NONE;
//
//	ckmc_raw_buffer_s msg_buff;
//	ckmc_raw_buffer_s *signature;
//	ckmc_hash_algo_e hash_algo = CKMC_HASH_SHA256;
//	ckmc_rsa_padding_algo_e pad_algo = CKMC_PKCS1_PADDING;
//
//	msg_buff.data = (unsigned char *)data;
//	msg_buff.size = strlen(data);
//
//	ret = ckmc_create_signature(private_key_alias, NULL, msg_buff, hash_algo, pad_algo, &signature);
//	if (CKMC_ERROR_NONE != ret)
//	{
//	   // Error handling
//	}
//	const char* base64_signature = g_base64_encode(signature->data, signature->size);
//	_D("%s", base64_signature);
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>

//int mqtt_subscribe(void *context, mqtt_delivered delivered, mqtt_msgarrvd msgarrvd, mqtt_connlost connlost)
//{
//    MQTTClient client;
//    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
//    int rc;
//
//    char client_id[500];
//    sprintf(client_id, "%s-%d", CLIENTID, rand() % 100000);
//
//    MQTTClient_create(&client, ADDRESS, client_id, MQTTCLIENT_PERSISTENCE_NONE, NULL);
//    conn_opts.keepAliveInterval = 20;
//    conn_opts.cleansession = 1;
//
//    MQTTClient_setCallbacks(client, context, connlost, msgarrvd, delivered);
//
//    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
////        _D("Failed to connect, return code %d\n", rc);
//        exit(EXIT_FAILURE);
//    }
//
//    const char* topic = "/some/topic/name";
//    _D("Subscribing to topic %s for client %s using QoS%d\n", topic, client_id, QOS);
//    MQTTClient_subscribe(client, topic, QOS);
//
////    MQTTClient_disconnect(client, 10000);
////    MQTTClient_destroy(&client);
//    return rc;
//}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// #include <yaca_crypto.h>
// #include <yaca_key.h>
// #include <yaca_error.h>

//static char* __concat(const char *multiline_str)
//{
//    char buffer[5000];
//    buffer[0] = '\0';
//    int r = 0;
//    const char *p = multiline_str;
//    char *q = strstr(p, "\n");
//    while (q != NULL) {
//    	int n = q - p;
//    	strncpy(&buffer[r], p, n);
//    	r += n;
//    	p = q + 1;
////        _D("%s", p);
//        q = strstr(p, "\n");
//    }
//	strcpy(&buffer[r], p);
//    _D("%s", buffer);
//	return strdup(buffer);
//}
//
//static char* __trim_priv(const char *pem_priv)
//{
//    char* trimmed_priv = strdup(strstr(pem_priv, "-----BEGIN PRIVATE KEY-----\n") + strlen("-----BEGIN PRIVATE KEY-----\n"));
//    trimmed_priv[strstr(trimmed_priv, "-----END PRIVATE KEY-----\n") - trimmed_priv] = '\0';
//    _D("%s", trimmed_priv);
//    return trimmed_priv;
//}
//
//static char* __trim_pub(const char *pem_pub)
//{
//    char* trimmed_pub = strdup(strstr(pem_pub, "-----BEGIN PUBLIC KEY-----\n") + strlen("-----BEGIN PUBLIC KEY-----\n"));
//    trimmed_pub[strstr(trimmed_pub, "-----END PUBLIC KEY-----\n") - trimmed_pub] = '\0';
//    _D("%s", trimmed_pub);
//    return trimmed_pub;
//}

//int ttd_onboarding_generate_key_pair(char **private_key, char **public_key)
//{
//    int ret;
//    yaca_context_h ctx = YACA_CONTEXT_NULL;
//    yaca_key_h priv_key = YACA_KEY_NULL;
//    yaca_key_h pub_key = YACA_KEY_NULL;
//
//    char *pem_priv = NULL;
//    size_t pem_priv_len;
//
//    char *pem_pub = NULL;
//    size_t pem_pub_len;
//
//    ret = yaca_initialize();
//    if (ret != YACA_ERROR_NONE)
//        goto exit;
//
//    /* Generate key pair */
//    ret = yaca_key_generate(YACA_KEY_TYPE_RSA_PRIV, YACA_KEY_LENGTH_2048BIT, &priv_key);
//    if (ret != YACA_ERROR_NONE)
//        goto exit;
//
//    ret = yaca_key_extract_public(priv_key, &pub_key);
//    if (ret != YACA_ERROR_NONE)
//        goto exit;
//
//	/* PEM private */
//	ret = yaca_key_export(priv_key, YACA_KEY_FORMAT_DEFAULT, YACA_KEY_FILE_FORMAT_PEM, NULL,
//						  &pem_priv, &pem_priv_len);
//	if (ret != YACA_ERROR_NONE)
//		goto exit;
//
//	_D("\t***** PEM exported private key: *****\n%.*s", (int)pem_priv_len, pem_priv);
//
//	/* PEM public */
//	ret = yaca_key_export(pub_key, YACA_KEY_FORMAT_DEFAULT, YACA_KEY_FILE_FORMAT_PEM, NULL,
//						  &pem_pub, &pem_pub_len);
//	if (ret != YACA_ERROR_NONE)
//		goto exit;
//
//	_D("\t***** PEM exported public key: *****\n%.*s", (int)pem_pub_len, pem_pub);
//
//    *private_key = strdup(pem_priv);
//    *public_key = strdup(pem_pub);
//
//exit:
//	yaca_key_destroy(priv_key);
//	yaca_key_destroy(pub_key);
//	yaca_context_destroy(ctx);
//
//	yaca_cleanup();
//	return ret;
//}
//
//int ttd_onboarding_sign(char **sign, const char *pem_priv, const char *data)
//{
//    int ret;
//    yaca_context_h ctx = YACA_CONTEXT_NULL;
//    yaca_key_h priv_key = YACA_KEY_NULL;
//    yaca_padding_e padding = YACA_PADDING_PKCS1;
//
//    char *signature = NULL;
//    size_t signature_len;
//
//    ret = yaca_initialize();
//    if (ret != YACA_ERROR_NONE)
//        goto exit;
//
//	ret = yaca_key_import(YACA_KEY_TYPE_RSA_PRIV, NULL, pem_priv, strlen(pem_priv), &priv_key);
//	if (ret != YACA_ERROR_NONE)
//		goto exit;
//
//    /* Sign */
//    {
//        /* Initialize sign context */
//        ret = yaca_sign_initialize(&ctx, YACA_DIGEST_SHA256, priv_key);
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        /* Set padding method */
//        ret = yaca_context_set_property(ctx, YACA_PROPERTY_PADDING, &padding, sizeof(padding));
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        /* Feeds the message */
//        ret = yaca_sign_update(ctx, data, strlen(data));
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        /* Get signature length and allocate memory */
//        ret = yaca_context_get_output_length(ctx, 0, &signature_len);
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        ret = yaca_malloc(signature_len, (void**)&signature);
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        /* Calculate signature */
//        ret = yaca_sign_finalize(ctx, signature, &signature_len);
//        if (ret != YACA_ERROR_NONE)
//            goto exit;
//
//        *sign = g_base64_encode(signature, signature_len);
//        _D("%s", *sign );
//
//        yaca_context_destroy(ctx);
//        ctx = YACA_CONTEXT_NULL;
//    }
//
//
//exit:
//    yaca_free(signature);
//    yaca_key_destroy(priv_key);
//    yaca_context_destroy(ctx);
//
//    yaca_cleanup();
//    return ret;
//}
