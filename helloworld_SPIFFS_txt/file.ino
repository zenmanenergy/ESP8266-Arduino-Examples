void removeFile(String path){
  Serial.print("removeFile:");
  Serial.println(path);
  if(SPIFFS.exists(path)){
    Serial.println("FILE EXISTS. Removing it");
    SPIFFS.remove(path);
  }
  if(!SPIFFS.exists(path)){
    Serial.println("FILE REMOVED");
  }
}

void writeFile(String path, String contents){
  Serial.print("writeFile:");
  Serial.println(path);
  Serial.print("contents:");
  Serial.println(contents);
  if(SPIFFS.exists(path)){
    Serial.println("FILE EXISTS");
  }
  File file = SPIFFS.open(path, "w");
  file.print(contents);
  file.close();
}
String readFile(String path){
  Serial.print("readFile:");
  Serial.println(path);
  String contents="";
  if(SPIFFS.exists(path)){
    Serial.println("FILE EXISTS");
    File file = SPIFFS.open(path, "r");

    while (file.available()) {
      contents+=char(file.read());
    }
    file.close();
  }
  
  
  return contents;
}

