#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  //creation and setting of variables	
  int len, i;
  char *result;
  int resultpointer = 0;
  int notvowelCount = 0;
  len = strlen(str);
  //for loop that counts the number of instances where a character isn't a vowel in a string
  for (i = 0; i < len; ++i) {
    if (tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u'){
	  notvowelCount++;
    }
  }
  //creates the result string
  result = (char*) calloc(notvowelCount+1, sizeof(char));
  //for loop that puts all the non-vowel characters into result
  for (i=0; i < len; ++i) {
    if (tolower(str[i]) != 'a' && tolower(str[i]) != 'e' && tolower(str[i]) != 'i' && tolower(str[i]) != 'o' && tolower(str[i]) != 'u'){
    result[resultpointer] = str[i];
    resultpointer++;
    }
  }
  //puts a null character in the last position of the result
  result[notvowelCount] = '\0';

  return result;

}
