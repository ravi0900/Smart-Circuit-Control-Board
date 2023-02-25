#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// char auth[] = "";
char ssid[] = "";
char pass[] = "";
BlynkTimer timer;                        
  BLYNK_WRITE (V0)
 {
  int value = param.asInt();
  Serial.println (value);
  if (value == 1)
   {
    digitalWrite (D1, LOW);
    Serial.println ("LED ON");
 }

  if (value == 0)
   {
     digitalWrite (D1, HIGH);
     Serial.println ("LED OFF");
   }
 }
   BLYNK_WRITE (V1)
   {
   int value = param.asInt();
   Serial.println (value);
   if (value == 1)
   {
     digitalWrite (D2, LOW);
     Serial. println ("LED ON");
   }
   if (value == 0)
    {
      digitalWrite (D2, HIGH);
      Serial.println ("LED OFF");
    }
 }
   BLYNK_WRITE (V2)
 {
  int value = param.asInt();
  Serial.println (value);
  if (value == 1)
   {
    digitalWrite (D3, LOW);
    Serial.println ("LED ON");
 }

  if (value == 0)
   {
     digitalWrite (D3, HIGH);
     Serial.println ("LED OFF");
   }
 }
  BLYNK_WRITE (V3)
 {
   int value = param.asInt();
   Serial.println (value);
   if (value == 1)
   {
     digitalWrite (D4, LOW);
     Serial. println ("LED ON");
   }
   if (value == 0)
    {
      digitalWrite (D4, HIGH);
      Serial.println ("LED OFF");
    }
 }
 
 BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}
 void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
 
  timer.setInterval(1000L, myTimerEvent);
  


}

void loop()
{
  Blynk.run();
  timer.run();
 
}

 
 