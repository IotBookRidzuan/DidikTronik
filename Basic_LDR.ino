void setup()
{
  pinMode(13, OUTPUT);
  pinMode(39, INPUT);
}

void loop()
{
  Serial.println(analogRead(A0)); 
  if(analogRead(A0)> 500){
    digitalWrite(13, LOW);
  }else{
    digitalWrite(13, HIGH);
  }
  delay(10);
}
