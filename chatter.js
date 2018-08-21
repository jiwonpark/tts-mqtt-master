// https://stackoverflow.com/a/35523939/396431

var mqtt = require('mqtt');

var MQTT_TOPIC          = "/some/topic/name";
// var MQTT_ADDR           = "mqtt://localhost";
var MQTT_ADDR           = "mqtt://MQTTBroker2.us-west-1.elasticbeanstalk.com";
var MQTT_PORT           = 1883;

/* This is not working as expected */
//var client = mqtt.connect({host: MQTT_ADDR, port:MQTT_PORT},{clientId: 'bgtestnodejs'});

const clientId = 'bgtestnodejs-' + (Math.random() * 10000).toFixed();

/* This works... */
var client  = mqtt.connect(MQTT_ADDR,{clientId: clientId, protocolId: 'MQIsdp', protocolVersion: 3, connectTimeout:1000, debug:true});

var readline = require('readline');

client.on('connect', function () {
    console.log(`Connected to ${MQTT_ADDR} ${clientId}!`);
    console.log(`Subscribing to ${MQTT_TOPIC}`);
    client.subscribe(MQTT_TOPIC);

    var rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout,
        terminal: false
    });
        
    rl.on('line', function(line){
        client.publish(MQTT_TOPIC, line);
    });
    
    // client.publish(MQTT_TOPIC, 'Hello mqtt');
});

client.on('message', function (topic, message) {
    // message is Buffer
    console.log(`'${message.toString()}' received for topic '${topic}'`);
    // client.end();
});

client.on('error', function(){
    console.log("ERROR")
    // client.end()
})
