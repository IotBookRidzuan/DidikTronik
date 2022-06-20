

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

void setup(void) {
  Serial.begin(115200);   // Set baudrate
  tft.init();              //initialize TFT display
  tft.invertDisplay(true); // activate display in invert
  tft.setRotation(1);       // Set rotation
  tft.fillScreen(TFT_BLACK); // Fill the initial display screen black

}

void loop() {

 
tft.fillScreen(TFT_BLACK); // black screen fill 
tft.setTextSize(2);        // set text size
tft.setCursor(0, 0);      //Set text initial coordianate
tft.setTextColor(TFT_RED, TFT_BLACK); //Set text colour text: red background text: black
tft.println("HELLO MALAYSIA"); // Display HELLO MALAYSIA 
delay(5000);  // wait for a second

}
