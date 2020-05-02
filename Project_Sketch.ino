// PushingBox Scenario DeviceID
char devid[] = "vD1DABE43FE7565D";
char serverName[] = "api.pushingbox.com";
boolean DEBUG = true;
#include <Bridge.h>
#include <HttpClient.h>

void setup() {
  // Bridge initialization + Status LED
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  digitalWrite(13, HIGH);

  Serial.begin(9600);
  while (!Serial); // wait for a serial connection
}

void loop() {
// Time calculations
// Source: User Jurs from forum.arduino.cc
unsigned long runMillis= millis();
unsigned long allSeconds=millis()/1000;
int runHours= allSeconds/3600;
int secsRemaining=allSeconds%3600;
int runMinutes=secsRemaining/60;
int runSeconds=secsRemaining%60;

char fullTime[21];
sprintf(fullTime,"Runtime%02d:%02d:%02d",runHours,runMinutes,runSeconds);
Serial.println(fullTime);
delay(1000);



// allows updates through pushingbox every 5 minutes
if((runMinutes % 5) == 0)
{
  //Source: https://github.com/marloft/PushingBoxGoogleSpreadsheet
  
  // Initialize the client library
  HttpClient client;
  

  // Make a HTTP request:  
  String APIRequest;
  APIRequest = String(serverName) + "/pushingbox?devid=" + String(devid)+ "&IDtag=100&TimeStamp=50&TempC=" + fullTime;
  client.get (APIRequest);
  
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();

  }
  Serial.flush();
  String UploadMessage;
  Serial.print("\n Uploaded temp value: ");
  Serial.print(fullTime);
  delay(5000);
  }
  
  
}
