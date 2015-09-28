


unsigned long previousMillis = 0;

void blinkDelay(int pin, unsigned long interval){
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    
    previousMillis = currentMillis;
    if (digitalRead(pin) == LOW){
      Serial.println("blink ON");
      digitalWrite(pin, HIGH);
    }
    else {
      Serial.println("blink OFF");
      digitalWrite(pin, LOW);
    }
    
  }
  
}
