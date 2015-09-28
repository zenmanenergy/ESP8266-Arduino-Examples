/*
 ESP8266 Hello World EEPROM by Steve Nelson
 EEPROM allows for persistant data even if the ESP loses power. EEPROM is kind of a pain in the
 ass to work with though. So I made a useful set of functions to work with it. I haven't
 converted this into a a C library yet. I'll do that soon.
  
 It has been tested on an esp12e (NodeMCU development board)
 This example code is in the public domain, use it however you want. 
*/ 
 void eepromBegin(int length){
  
}
void eepromSet(String name, String newvalue){
  String list=eepromDelete(name);
  list=list + "&" + name + "=" + newvalue;
  for (int i = 0; i < 512; ++i){
    EEPROM.write(i,'\n');
  }
  EEPROM.commit();
  
  for (int i = 0; i < list.length(); ++i){
    EEPROM.write(i,list.charAt(i));
  }
  EEPROM.commit();
  
}
String eepromDelete(String name){
  
  int nameOfValue;
  String currentName="";
  String currentValue="";
  int foundIt=0;
  char letter;
  String newList="";
  for (int i = 0; i < 512; ++i){
      letter= char(EEPROM.read(i));
      if (letter=='\n'){
        if (foundIt==1){
        }else if (newList.length()>0){
           newList+="=" + currentValue;
        }
        break;
      } else if (letter=='&'){
        nameOfValue=0;
        currentName="";
        if (foundIt==1){
          foundIt=0;
        }else if (newList.length()>0){
           newList+="=" + currentValue;
        }
      
        
      } else if (letter=='='){
        if (currentName==name){
           foundIt=1;
        }else{
           foundIt=0;
           newList+="&" + currentName;
        }
        nameOfValue=1;
        currentValue="";
      }
      else{
        if (nameOfValue==0){
          currentName+=letter;
        }else{
          currentValue+=letter;
        }
      } 
  }
  
  for (int i = 0; i < 512; ++i){
    EEPROM.write(i,'\n');
  }
  EEPROM.commit();
  for (int i = 0; i < newList.length(); ++i){
    EEPROM.write(i,newList.charAt(i));
  }
  EEPROM.commit();
  return newList;
}
void eepromClear(){
  Serial.println("eepromClear");
  for (int i = 0; i < 512; ++i){
    EEPROM.write(i,'\n');
  }
  EEPROM.commit();
}
String eepromList(){
  char letter;
  String list="";
  for (int i = 0; i < 512; ++i){
      letter= char(EEPROM.read(i));
      if (letter=='\n'){
        break;
      }else{
        list+=letter;
      } 
  }
  return list;
}
String eepromGet(String name){
  int nameOfValue;
  String currentName="";
  String currentValue="";
  int foundIt=0;
  String value="";
  char letter;
  for (int i = 0; i < 512; ++i){
      letter= char(EEPROM.read(i));
      if (letter=='\n'){
        if (foundIt==1){
          value=currentValue; 
        }
        break;
      } else if (letter=='&'){
        nameOfValue=0;
        currentName="";
        if (foundIt==1){
          value=currentValue;
          break; 
        }
      } else if (letter=='='){
        if (currentName==name){
           foundIt=1;
        }else{
        }
        nameOfValue=1;
        currentValue="";
      }
      else{
        if (nameOfValue==0){
          currentName+=letter;
        }else{
          currentValue+=letter;
        }
      } 
  }
  return value;
}  
