String nameValueFilePath="/config.txt";

String dataGet(String name){
  String value="";
  String contents=readFile(nameValueFilePath);
  String nameSearch="&"+name+"=";
  int findOldVarStart=contents.indexOf(nameSearch);
  if (findOldVarStart > -1){
    int findOldVarEnd=contents.indexOf("&",findOldVarStart+1);
    if (findOldVarEnd==-1){
      findOldVarEnd=contents.length();
    }
    value=contents.substring(findOldVarStart+nameSearch.length(), findOldVarEnd);
  }
  return value;
}

void dataSet(String name, String value){
  Serial.println("dataSet");
  Serial.print("name:");
  Serial.println(name);
  Serial.print("value:");
  Serial.println(value);
  String contents=readFile(nameValueFilePath);
  int findOldVarStart=contents.indexOf("&"+name+"=");
  if (findOldVarStart > -1){
    int findOldVarEnd=contents.indexOf("&",findOldVarStart+1);
    if (findOldVarEnd==-1){
      contents.remove(findOldVarStart);
    }else{
      contents.remove(findOldVarStart,findOldVarEnd-findOldVarStart);
    }
    
  }
  contents+="&"+name+"="+value;
  writeFile(nameValueFilePath, contents);
}
