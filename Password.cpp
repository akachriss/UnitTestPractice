#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;

  if(phrase.length() == 0)
  {
    repetition = 0;
    return repetition;
  }

  while( index < phrase.length()-1 && tolower(phrase[index]) == tolower(phrase[index+1]) ){
    repetition++;
    index++;
  }
  return repetition;
}

//Has at least one upper case AND lower case character
bool Password::has_mixed_case(string phrase)
{
  bool upper = false;
  bool lower = false;

  for(char c : phrase)
  {
    if(isupper(c))
    {
      upper = true;
    }
    if(islower(c)){
      lower = true;
    }
  }

  if(upper && lower){
    return true;
  }

  return false;
}
/*
 receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
*/

void Password::set(string phrase)
{
  int length = phrase.length();

  if(length < 8){
    return;
  }else{
      bool mixed = has_mixed_case(phrase);
      int lead = count_leading_characters(phrase);
      bool valid = authenticate(phrase);
      if(!mixed && lead <= 3 && !valid)
      {
        /*
       for(string &str : pass_history)
       {
          if(str == phrase){
            return;
          }
       }
       */
       pass_history.push_back(phrase);
      }
  }
  return;
}

bool Password::authenticate(string phrase)
{
  for(string &str : pass_history)
  {
    if(str == phrase){
        return true;
    }
  }
  return false;
}