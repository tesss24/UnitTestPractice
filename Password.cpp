#include "Password.h"
#include <string>
#include <cctype>
#include<iostream>

using std::string;
using std::cout;
using std::endl;

Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string password){
  int upper = false;
  int lower = false;
  int index = 0;
  while( index <= password.length()-1 ){
    if (isupper(password[index])){
      upper = true;
    }
    if (islower(password[index])){
      lower = true;
    }
    if (upper == true && lower == true){
      return true;
    }
    index++;
  }
  return false;
}

void Password::set(string password){
  if (password.length() < 8){
    cout << "Too short" << endl;
    return;
  }
  int count = count_leading_characters(password);
  if (count > 3){
    cout << "Can't have more then three of the same leading character" << endl;
    return;
  }
  if(!has_mixed_case(password)){
    cout << "Needs at least one upper case and one lower case letter" << endl;
    return;
  }
  for( int i = 0; i < pass_history.size(); i++){
    if (password == pass_history[i]){
      cout << "Can't be an already used password" << endl;
      return;
    }
  }
  pass_history.push_back(password);
  return;
}

bool Password::authenticate(string password){
  if(pass_history.size() > 0){
    if (password == pass_history[pass_history.size()-1]){
      return true;
    }
  }
  return false;
}

