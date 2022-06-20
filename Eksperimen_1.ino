//  Isytiharkan pin untuk Butang dan LED
int buttonPin = 32;
int LED = 26;

void setup() {
   // Tentukan pin #12 sebagai input dan aktifkan internal pull-up resistor
   pinMode(buttonPin, INPUT_PULLUP);
   // Tentukan pin #13 sebagai output, untuk LED
   pinMode(LED, OUTPUT);
}

void loop(){
   // Baca nilai input sama ada 1 atau 0
   int buttonValue = digitalRead(buttonPin);
   if (buttonValue == LOW){
      // Jika butang ditekan,  LED Menyala
  digitalWrite(LED, HIGH);   // LED Menyala(HIGH is the voltage level)
  delay(1000);                       // Tunggu beberapa saat
  digitalWrite(LED, LOW);    // LeD tidak menyala (LOW is the voltage level)
  delay(1000);                       // Tunggu beberapa saat
   } else {
      // Jika tidak, LED tidak menyala
      digitalWrite(LED, LOW);
   }
}
