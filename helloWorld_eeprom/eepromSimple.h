#ifndef eepromSimple_h
#define eepromSimple_h
#include <EEPROM.h>
#include <Arduino.h>

//#include <ESP.h>



class eepromSimple
{
  public:
    eepromSimple();
    void begin(int size);
    void set(String name, String value);
    void remove(String name);
    String get(String name);
    String list();
    void setFromList(String nameValueList);
    void clear();
  private:
    void commit();
    int _size;
    String _eepromList="";
    void removeFromList(String name);
    
};
#endif
