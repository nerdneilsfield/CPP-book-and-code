#include <regex>
#include <string>
#include <iostream>

using namespace std;

void out(bool b){
  cout << (b ?" found" : "not found") << endl;
}

int main(){

  string data  = "<tag>value</tag>";
  regex reg1("<.*>.*</.*>");
  bool found = regex_match("<tag>value</tag>", reg1);
  out(found);
  

  regex reg2("<(.*)>.*</\\1>");
  found = regex_match(data, reg2);
  out(found);
  regex reg3("<\\(.*\\)>.*</\\1>", regex_constants::grep);
  found = regex_match(data, reg3);
  out(found);

  return 0;
}
