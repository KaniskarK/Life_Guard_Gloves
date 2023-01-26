#include <ESP8266WiFi.h>    //esp8266 library
#include <FirebaseArduino.h>     //firebase library
#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);
#include <OneWire.h>
#include <DallasTemperature.h>
const int SensorDataPin = 14;
OneWire oneWire(SensorDataPin);
DallasTemperature sensors(&oneWire);
#define FIREBASE_HOST ""//the project name address from firebase id
#define FIREBASE_AUTH ""//the secret key generated from firebase
#define WIFI_SSID "R&D LABS"                  // wifi name
#define WIFI_PASSWORD ""                 //password of wifi
const int PulseWire = 0;
float temp;
float Fahrenheit = 0;
int Threshold = 550;
int value = 0;
void setup() {
  Serial.begin(9600);
  delay(1000);
  sensors.begin();
  ads.begin();
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
}
void loop()
{
  int16_t adc0, adc1, adc2, adc3;
  adc0 = ads.readADC_SingleEnded(0);
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  String vib_data = String(adc0);
  String myBPM = String(adc1);
  String sensorValue =String(adc2);
  String flexValue = String(adc3);
  sensors.requestTemperatures();
  float temperature_Celsius = sensors.getTempCByIndex(0);
  float temperature_Fahrenheit = sensors.getTempFByIndex(0);
  Serial.print("Temperature: ");
  Serial.print(temperature_Celsius);
  Serial.println(" ºC");
  Serial.print("Temperature: ");
  Serial.print(temperature_Fahrenheit);
  Serial.println(" ºF");
  Serial.println("");
  Serial.println("temp:");
  Serial.println(temp);
  String t = String(temp);
  Serial.println("Fahrenheit:");
  Serial.println(Fahrenheit);
  String Fah = String(Fahrenheit);
  Serial.println("vib_data:");
  Serial.println(vib_data);
  Serial.println("myBPM:");
  Serial.println(myBPM);
  Serial.println("sensorValue:");
  Serial.println(sensorValue);
  Serial.println("flexValue:");
  Serial.println(flexValue);
  delay(1000);
  Firebase.pushString("/Healthcare/Temperature", t);      //setup path and send readings
  Firebase.pushString("/Healthcare/Temperature", Fah);      //setup path and send readings
  Firebase.pushString("/Healthcare/Heartbeat", myBPM);
  Firebase.pushString("/Healthcare/Gasvalue", sensorValue);
  Firebase.pushString("/Healthcare/Flexrange1", flexValue);
  Firebase.pushString("/Healthcare/vibration", vib_data);
  delay(15000);
}
