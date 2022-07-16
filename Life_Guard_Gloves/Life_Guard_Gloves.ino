#include <ESP8266WiFi.h>    //esp8266 library
#include <FirebaseArduino.h>     //firebase library
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library
#define FIREBASE_HOST "healthcare-7c153.firebaseio.com"  // the project name address from firebase id
#define FIREBASE_AUTH "qxAJyMdw8DdKt2RIvaBZdlyRBa7GcwbX1pfiv6Cm"  // the secret key generated from firebase
#define WIFI_SSID "XXXXXXXXXXXX"                  // wifi name 
#define WIFI_PASSWORD "XXXXXXXXX"                 //password of wifi 
const int PulseWire = 0;  
float temp;
float Fahrenheit=0;
int Threshold = 550;    
int sensorvalue=A0;
const int flexPin = A1; 
const int flexPin = A2; 
const int flexPin = A3 
const int flexPin = A4; 
int motorPin = 3;
int value=0;
motorpin==value;
                                                    
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(motorPin, OUTPUT );
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   
  DS18B20.begin();                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);    
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                  //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);     // connect to firebase
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created!");
  }                         //Start reading dht sensor
}
void gas_level()
{
   int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);
}
void flex_sensor()
{
  int flexValue1;
  int flexValue2;
  int flexValue3;
  int flexValue4;
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue1);
  Serial.print("sensor: ");
  Serial.println(flexValue2);
  Serial.print("sensor: ");
  Serial.println(flexValue3);
  Serial.print("sensor: ");
  Serial.println(flexValue4);
  }
void loop() { 
if(motorPin==HIGH)
{
    digitalWrite(motorPin, HIGH);
    Serial.println("vibration detected");
    Serial.println(value);
    delay(1000);
}
else{
    digitalWrite(motorPin, LOW);
    Serial.println("vibration not detected");
    Serial.println(value);
    delay(1000);
}
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit
  Serial.println(temp);
  Serial.println(Fahrenheit);
  delay(4000);
int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

  if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
    Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
    Serial.print("BPM: ");
    Serial.println(myBPM);                        // Print the BPM value
    }
delay(20);
gas_level()
flex_sensor()
  Firebase.pushString("/Healthcare/Temperature", temp);         //setup path and send readings
  Firebase.pushString("/Healthcare/Temperature", Fahrenheit);        //setup path and send readings
  Firebase.pushString("/Healthcare/Heartbeat", myBPM);   
  Firebase.pushString("/Healthcare/Gasvalue", sensorValue);  
  Firebase.pushString("/Healthcare/Flexrange1", flexValue1);    
  Firebase.pushString("/Healthcare/Flexrange2", flexValue2);    
  Firebase.pushString("/Healthcare/Flexrange3", flexValue3);    
  Firebase.pushString("/Healthcare/Flexrange4", flexValue4);    
  Firebase.pushString("/Healthcare/vibration", value); 
   
}
#include <ESP8266WiFi.h>    //esp8266 library
#include <FirebaseArduino.h>     //firebase library
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library
#define FIREBASE_HOST "healthcare-7c153.firebaseio.com"  // the project name address from firebase id
#define FIREBASE_AUTH "qxAJyMdw8DdKt2RIvaBZdlyRBa7GcwbX1pfiv6Cm"  // the secret key generated from firebase
#define WIFI_SSID "XXXXXXXXXXXX"                  // wifi name 
#define WIFI_PASSWORD "XXXXXXXXX"                 //password of wifi 
const int PulseWire = 0;  
float temp;
float Fahrenheit=0;
int Threshold = 550;    
int sensorvalue=A0;
const int flexPin = A1; 
const int flexPin = A2; 
const int flexPin = A3 
const int flexPin = A4; 
int motorPin = 3;
int value=0;
motorpin==value;
                                                    
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(motorPin, OUTPUT );
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   
  DS18B20.begin();                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);    
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                  //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);     // connect to firebase
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created!");
  }                         //Start reading dht sensor
}
void gas_level()
{
   int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);
}
void flex_sensor()
{
  int flexValue1;
  int flexValue2;
  int flexValue3;
  int flexValue4;
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue1);
  Serial.print("sensor: ");
  Serial.println(flexValue2);
  Serial.print("sensor: ");
  Serial.println(flexValue3);
  Serial.print("sensor: ");
  Serial.println(flexValue4);
  }
void loop() { 
if(motorPin==HIGH)
{
    digitalWrite(motorPin, HIGH);
    Serial.println("vibration detected");
    Serial.println(value);
    delay(1000);
}
else{
    digitalWrite(motorPin, LOW);
    Serial.println("vibration not detected");
    Serial.println(value);
    delay(1000);
}
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit
  Serial.println(temp);
  Serial.println(Fahrenheit);
  delay(4000);
int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

  if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
    Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
    Serial.print("BPM: ");
    Serial.println(myBPM);                        // Print the BPM value
    }
delay(20);
gas_level()
flex_sensor()
  Firebase.pushString("/Healthcare/Temperature", temp);         //setup path and send readings
  Firebase.pushString("/Healthcare/Temperature", Fahrenheit);        //setup path and send readings
  Firebase.pushString("/Healthcare/Heartbeat", myBPM);   
  Firebase.pushString("/Healthcare/Gasvalue", sensorValue);  
  Firebase.pushString("/Healthcare/Flexrange1", flexValue1);    
  Firebase.pushString("/Healthcare/Flexrange2", flexValue2);    
  Firebase.pushString("/Healthcare/Flexrange3", flexValue3);    
  Firebase.pushString("/Healthcare/Flexrange4", flexValue4);    
  Firebase.pushString("/Healthcare/vibration", value); 
   
}
#include <ESP8266WiFi.h>    //esp8266 library
#include <FirebaseArduino.h>     //firebase library
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library
#define FIREBASE_HOST "healthcare-7c153.firebaseio.com"  // the project name address from firebase id
#define FIREBASE_AUTH "qxAJyMdw8DdKt2RIvaBZdlyRBa7GcwbX1pfiv6Cm"  // the secret key generated from firebase
#define WIFI_SSID "XXXXXXXXXXXX"                  // wifi name 
#define WIFI_PASSWORD "XXXXXXXXX"                 //password of wifi 
const int PulseWire = 0;  
float temp;
float Fahrenheit=0;
int Threshold = 550;    
int sensorvalue=A0;
const int flexPin = A1; 
const int flexPin = A2; 
const int flexPin = A3 
const int flexPin = A4; 
int motorPin = 3;
int value=0;
motorpin==value;
                                                    
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(motorPin, OUTPUT );
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   
  DS18B20.begin();                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);    
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                  //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);     // connect to firebase
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created!");
  }                         //Start reading dht sensor
}
void gas_level()
{
   int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);
}
void flex_sensor()
{
  int flexValue1;
  int flexValue2;
  int flexValue3;
  int flexValue4;
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue1);
  Serial.print("sensor: ");
  Serial.println(flexValue2);
  Serial.print("sensor: ");
  Serial.println(flexValue3);
  Serial.print("sensor: ");
  Serial.println(flexValue4);
  }
void loop() { 
if(motorPin==HIGH)
{
    digitalWrite(motorPin, HIGH);
    Serial.println("vibration detected");
    Serial.println(value);
    delay(1000);
}
else{
    digitalWrite(motorPin, LOW);
    Serial.println("vibration not detected");
    Serial.println(value);
    delay(1000);
}
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit
  Serial.println(temp);
  Serial.println(Fahrenheit);
  delay(4000);
int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

  if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
    Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
    Serial.print("BPM: ");
    Serial.println(myBPM);                        // Print the BPM value
    }
delay(20);
gas_level()
flex_sensor()
  Firebase.pushString("/Healthcare/Temperature", temp);         //setup path and send readings
  Firebase.pushString("/Healthcare/Temperature", Fahrenheit);        //setup path and send readings
  Firebase.pushString("/Healthcare/Heartbeat", myBPM);   
  Firebase.pushString("/Healthcare/Gasvalue", sensorValue);  
  Firebase.pushString("/Healthcare/Flexrange1", flexValue1);    
  Firebase.pushString("/Healthcare/Flexrange2", flexValue2);    
  Firebase.pushString("/Healthcare/Flexrange3", flexValue3);    
  Firebase.pushString("/Healthcare/Flexrange4", flexValue4);    
  Firebase.pushString("/Healthcare/vibration", value); 
   
}
#include <ESP8266WiFi.h>    //esp8266 library
#include <FirebaseArduino.h>     //firebase library
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library
#define FIREBASE_HOST "healthcare-7c153.firebaseio.com"  // the project name address from firebase id
#define FIREBASE_AUTH "qxAJyMdw8DdKt2RIvaBZdlyRBa7GcwbX1pfiv6Cm"  // the secret key generated from firebase
#define WIFI_SSID "XXXXXXXXXXXX"                  // wifi name 
#define WIFI_PASSWORD "XXXXXXXXX"                 //password of wifi 
const int PulseWire = 0;  
float temp;
float Fahrenheit=0;
int Threshold = 550;    
int sensorvalue=A0;
const int flexPin = A1; 
const int flexPin = A2; 
const int flexPin = A3 
const int flexPin = A4; 
int motorPin = 3;
int value=0;
motorpin==value;
                                                    
void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(motorPin, OUTPUT );
  pulseSensor.analogInput(PulseWire);
  pulseSensor.setThreshold(Threshold);   
  DS18B20.begin();                
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);    
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                  //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);     // connect to firebase
  if (pulseSensor.begin()) {
    Serial.println("PulseSensor object created!");
  }                         //Start reading dht sensor
}
void gas_level()
{
   int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(200);
}
void flex_sensor()
{
  int flexValue1;
  int flexValue2;
  int flexValue3;
  int flexValue4;
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  flexValue = analogRead(flexPin);
  Serial.print("sensor: ");
  Serial.println(flexValue1);
  Serial.print("sensor: ");
  Serial.println(flexValue2);
  Serial.print("sensor: ");
  Serial.println(flexValue3);
  Serial.print("sensor: ");
  Serial.println(flexValue4);
  }
void loop() { 
if(motorPin==HIGH)
{
    digitalWrite(motorPin, HIGH);
    Serial.println("vibration detected");
    Serial.println(value);
    delay(1000);
}
else{
    digitalWrite(motorPin, LOW);
    Serial.println("vibration not detected");
    Serial.println(value);
    delay(1000);
}
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Fahrenheit = DS18B20.toFahrenheit(temp); // Fahrenheit
  Serial.println(temp);
  Serial.println(Fahrenheit);
  delay(4000);
int myBPM = pulseSensor.getBeatsPerMinute();      // Calculates BPM

  if (pulseSensor.sawStartOfBeat()) {               // Constantly test to see if a beat happened
    Serial.println("♥  A HeartBeat Happened ! "); // If true, print a message
    Serial.print("BPM: ");
    Serial.println(myBPM);                        // Print the BPM value
    }
delay(20);
gas_level()
flex_sensor()
  Firebase.pushString("/Healthcare/Temperature", temp);         //setup path and send readings
  Firebase.pushString("/Healthcare/Temperature", Fahrenheit);        //setup path and send readings
  Firebase.pushString("/Healthcare/Heartbeat", myBPM);   
  Firebase.pushString("/Healthcare/Gasvalue", sensorValue);  
  Firebase.pushString("/Healthcare/Flexrange1", flexValue1);    
  Firebase.pushString("/Healthcare/Flexrange2", flexValue2);    
  Firebase.pushString("/Healthcare/Flexrange3", flexValue3);    
  Firebase.pushString("/Healthcare/Flexrange4", flexValue4);    
  Firebase.pushString("/Healthcare/vibration", value); 
   
}
