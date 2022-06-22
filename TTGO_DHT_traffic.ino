
int LEDM = 21;
int LEDK = 22;
int LEDH = 17;
int FAN  = 13;

#define DHTPin    33

#include <TFT_eSPI.h>
#include <DHT.h>


TFT_eSPI tft = TFT_eSPI();
DHT dht(DHTPin,DHT11);

float t,h,temperature,humidity;
unsigned long int timer;

String message;


void setup()
{
  Serial.begin(115200);
  dht.begin();

  tft.init();
  tft.invertDisplay(true);
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextSize(2);
  pinMode(LEDM, OUTPUT);
  pinMode(LEDK, OUTPUT);
  pinMode(LEDH, OUTPUT);
  pinMode(FAN, OUTPUT);

}

void loop()
{
 
  t=dht.readTemperature();
  h=dht.readHumidity();
  if(!isnan(t) && !isnan(h))
  {
    temperature = t;
    humidity = h;
  }

  tft.setCursor(0,0);
  tft.println("    DHT11 Sensor    ");

  tft.println();
  message="Temperature";
  while(message.length()<19) message=" "+message+" ";
  tft.println(message);
  message=String(temperature,2)+" degC";
  while(message.length()<19) message=" "+message+" ";
  tft.println(message);
  message="Humidity";
  while(message.length()<19) message=" "+message+" ";
  tft.println(message);
  message=String(humidity,2)+" %";
  while(message.length()<19) message=" "+message+" ";
  tft.println(message);
 delay(3000);
 
 if (t >= 30)
  {
    digitalWrite(FAN, LOW);
    digitalWrite(LEDM, HIGH);
    digitalWrite(LEDK, LOW);
    digitalWrite(LEDH, LOW);
    tft.fillScreen(TFT_RED); 
    tft.setCursor(90, 40);      //Set text initial coordianate                         
    tft.setTextColor(TFT_BLACK, TFT_RED);         //Set text colour text: YELLOW background text: black
    tft.println("PANAS!!");                       // Display LED OFF when LED is Off 
    delay(500);                                   // wait for a second
  }
  else if (t >= 26 && t < 30  )
  {
    digitalWrite(FAN, HIGH);
    digitalWrite(LEDM, LOW);
    digitalWrite(LEDK, HIGH);
    digitalWrite(LEDH, LOW);
    tft.fillScreen(TFT_YELLOW); 
    tft.setCursor(90, 40);      //Set text initial coordianate                         
    tft.setTextColor(TFT_BLACK, TFT_YELLOW);         //Set text colour text: YELLOW background text: black
    tft.println("SUHU BIASA");                       // Display LED OFF when LED is Off 
    delay(500);                                   // wait for a second
  }
else if (t < 26 )
  {
    digitalWrite(FAN, HIGH);
    digitalWrite(LEDM, LOW);
    digitalWrite(LEDK, LOW);
    digitalWrite(LEDH, HIGH);
    tft.fillScreen(TFT_GREEN); 
    tft.setCursor(90, 40);      //Set text initial coordianate                         
    tft.setTextColor(TFT_BLACK, TFT_GREEN);         //Set text colour text: YELLOW background text: black
    tft.println("SUHU SEJUK");                       // Display LED OFF when LED is Off 
    delay(500);                                   // wait for a second
  }



    
    Serial.println("Temperature="+String(temperature)+"degC Humidity="+String(humidity)+"%");

}
