
#include <TFT_eSPI.h>
const int ldrPin = 39;    
TFT_eSPI tft = TFT_eSPI();

unsigned long int timer;

String message;

void setup()
{
  Serial.begin(115200);

  pinMode(ldrPin, INPUT);
  tft.init();
  tft.invertDisplay(true);
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(2);
  pinMode(13, OUTPUT);
  pinMode(39, INPUT);

}  
void loop()
{
 Serial.println(analogRead(A0));
 int ldrStatus = analogRead(A0); 
  if(analogRead(A0)> 500){
    digitalWrite(13, LOW);
  }else{
    digitalWrite(13, HIGH);
  }
  delay(100);
 

  tft.setCursor(0,0);
  tft.println("    LDR Sensor    ");
  tft.setCursor(40,50);
  tft.println("LDR="+String(4095-ldrStatus)+"  CAHAYA");
 
 
}
