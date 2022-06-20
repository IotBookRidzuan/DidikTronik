

// Declare the pins for the Button and the LED
int buttonPin = 32;
int LED = 26;

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

void setup(void) {
  Serial.begin(115200);   // Set baudrate
  tft.init();              //initialize TFT display
  tft.invertDisplay(true); // activate display in invert
  tft.setRotation(1);       // Set rotation
  tft.fillScreen(TFT_BLACK); // Fill the initial display screen black
 // Define pin #26 as input and activate the internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
 // Define pin #27 as output, for the LED
  pinMode(LED, OUTPUT);
}

void loop() {
 
tft.fillScreen(TFT_BLACK); // black screen fill 
tft.setTextSize(3);        // set text size


// Read the value of the input. It can either be 1 or 0
int buttonValue = digitalRead(buttonPin);
  if (buttonValue == LOW){
      // If button pushed, Blinking LED
  digitalWrite(LED, HIGH);                       // turn the LED on (HIGH is the voltage level)
  tft.setCursor(0, 0);      //Set text initial coordianate
  tft.setTextColor(TFT_GREEN, TFT_BLACK);         //Set text colour text: GREEN background text: black
  tft.println("LED ON");                        // Display LED ON when LED is On
  delay(1000);                                  // wait for a second
  digitalWrite(LED, LOW);                       // turn the LED off by making the voltage LOW
  tft.setCursor(0, 0);      //Set text initial coordianate                         
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);         //Set text colour text: YELLOW background text: black
  tft.println("LED OFF");                       // Display LED OFF when LED is Off 
  delay(1000);                                   // wait for a second
   } else {
      // Otherwise, turn the LED off or button not press
      digitalWrite(LED, LOW);                   // turn the LED off by making the voltage LOW
      tft.setCursor(0, 0);      //Set text initial coordianate
      tft.setTextColor(TFT_RED, TFT_BLACK);     //Set text colour text: red background text: black
      tft.println("OFF BLINK");                 // Display LED OFF when LED is Off
      delay(1000);                              // wait for a second
   }

}
