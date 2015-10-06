#include "./eepromSimple.h"



#define DEBUG
#define DEBUG_OUTPUT Serial

eepromSimple::eepromSimple()
{

}

void eepromSimple::begin(int size)
{
  _size=size;
  
  EEPROM.begin(_size);
  list();
  
  //#ifdef DEBUG
  //  DEBUG_OUTPUT.println(_eepromList);
  //#endif
  
}


void eepromSimple::clear()
{
  _eepromList="";
  commit();
}
String eepromSimple::list(){
  
  char letter;
  _eepromList="";
  for (int i = 0; i < _size; ++i){
      letter= char(EEPROM.read(i));
      if (letter=='\n'){
        break;
      }else{
        _eepromList+=letter;
      }
  }
  
  return _eepromList;
}
void eepromSimple::set(String name, String newvalue){
  removeFromList(name);
  _eepromList=_eepromList + "&" + name + "=" + newvalue;
  commit();
}
String eepromSimple::get(String name){
  String value;
  int findOldVarStart=_eepromList.indexOf("&"+name+"=");
  if (findOldVarStart > -1){
    int offset = name.length()+2;
    int findOldVarEnd=_eepromList.indexOf("&",findOldVarStart+1);
    if (findOldVarEnd > -1){
      //remove the new variable from the old list.
      value=_eepromList.substring(findOldVarStart+offset, findOldVarEnd);
    }else{
      //remove the new variable from the old list.
      value=_eepromList.substring(findOldVarStart+offset);
    }
  }

  return value;
}

void eepromSimple::remove(String name){
  removeFromList(name);
  commit();
}
void eepromSimple::removeFromList(String name){
  for (int i=0;i<_eepromList.length(); i++){
    int findOldVarStart=_eepromList.indexOf("&"+name+"=");
    if (findOldVarStart > -1){
      int findOldVarEnd=_eepromList.indexOf("&",findOldVarStart+1);
      if (findOldVarEnd > -1){
        //remove the new variable from the old list.
        _eepromList.remove(findOldVarStart, findOldVarEnd);
      }else{
        //remove the new variable from the old list.
        _eepromList.remove(findOldVarStart);
      }
    } else{
      break;
    }
  }
}
void eepromSimple::setFromList(String nameValueList){
  
  
  String newList="";
  
  int currentCharacter=0;
  String nameValue;
  String varName;
  String varValue;
  bool shouldBreak=false;
  
  for (int j=0; j < nameValueList.length(); ++j){
    int findAmp=nameValueList.indexOf('&', currentCharacter+1);
    if (findAmp > -1){
      nameValue=nameValueList.substring(currentCharacter+1, findAmp);
    }else{
      nameValue=nameValueList.substring(currentCharacter+1);
      shouldBreak=true;
    }
    currentCharacter=currentCharacter+1;
    varName=nameValue.substring(0, nameValue.indexOf("="));
    //varValue=nameValue.substring(nameValue.indexOf("=")+1);

    removeFromList(varName);
    
    if (shouldBreak){
      break;
    }
  }
  //combine the new list and the older list (minus the overwritten variables);
  _eepromList=nameValueList+_eepromList;
  
  commit();
  
}
void eepromSimple::commit(){
  for (int i = 0; i < _eepromList.length(); ++i){
    EEPROM.write(i,_eepromList.charAt(i));
    
  }
  for (int i = _eepromList.length(); i < _size; ++i){
    EEPROM.write(i,'\n');
  }
  EEPROM.commit();
}
