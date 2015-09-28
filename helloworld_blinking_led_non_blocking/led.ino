


int ledState = LOW;
long previousMillis = 0;
long currentBlink=-2;

void blinkDelay(int pin, long interval, long numberOfBlinks){
  if (numberOfBlinks==0){
    digitalWrite(pin,LOW);
  } else if (numberOfBlinks==1){
    digitalWrite(pin,HIGH);
  } else{
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      if (ledState == LOW){
        currentBlink++;
        ledState = HIGH;
      }
      else {
        ledState = LOW;
      }
      if (currentBlink >= numberOfBlinks){
        currentBlink=-2;
        ledState = LOW;
      }
      if (currentBlink < 0){
        ledState = LOW;
      }
      digitalWrite(pin, ledState);
    }
  }
}
