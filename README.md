# tts-mqtt
Demonstration of using paho-mqtt on Tizen-based ARTIK 530s device (the Subscriber) to receive MQTT messages from Node.js-based MQTT client (the Publisher) via Mosquitto MQTT Broker

## What is MQTT?
https://pagefault.blog/2017/03/02/using-local-mqtt-broker-for-cloud-and-interprocess-communication/

## Prerequisites
* Install Node.js
* Install Tizen Studio
* Install Extension SDK for ARTIK 530s
* Install corresponding binary on ARTIK 530s device
* Connect the device to the Internet via WiFi

## Build and run Tizen MQTT client (subscriber role)
1. In Tizen Studio, File > Import > Tizen Project > Next > Browse > tts-mqtt-test > OK > Next > Finish
2. Right click tts-mqtt-test > Build Project
3. Right click tts-mqtt-test > Run As > Tizen Native Application
4. sdb dlog TTD

## Run Node.js MQTT client (publisher role)
1. npm install --save mqtt
2. node publisher.js

## Deploy my own MQTT broker on AWS (Advanced)

### Create Elastic Beanstalk Environment with a **Network** Load Balancer
1. [Install EB CLI (Command-Line Interface)](https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/eb-cli3-install.html)
2. [Configure EB CLI](https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/eb-cli3-configuration.html)
3. [Create EB Environment and configure a Network Load Balancer using the EB CLI](https://docs.aws.amazon.com/elasticbeanstalk/latest/dg/environments-cfg-nlb.html)

### Configure the EB Environment for Mosquitto
1. Configure Security Group(https://docs.aws.amazon.com/AWSEC2/latest/UserGuide/using-network-security.html)
   * Open port 1883 for all IPs
2. [Configure Load Balancer]
   * AWS > Elastic Beanstalk > Choose the environment > Configuration > Load Balancer > Modify > Add listener > Port: 1883 > Add > Apply
3. Configure Proxy
   * AWS > EC2 > [Load Balancers](http://console.aws.amazon.com/ec2/v2/home#LoadBalancers) > (Choose the Load Balancer corresponding to the running EC2 instance) > Listeners tab (in the bottom pane) > Add listener > TCP:1883 > Save
### Download [Docker image preconfigured for Mosquitto](https://hub.docker.com/r/ansi/mosquitto/)
### Upload the Dockerfile
