#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 1024

// from Avery/Leah Lab 2: https://github.com/UMM-CSci-3403-Fall-2018/lab-2-memory-management-in-c-wild-cats/blob/master/disemvowel/disemvowel.c
bool is_vowel(char c) {
    /*
     * Returns true if c is a vowel (upper or lower case), and
     * false otherwise.
     */
  char *vowels = (char*) calloc(11, sizeof(char));
  vowels[0] = 'a';
  vowels[1] = 'e';
  vowels[2] = 'i';
  vowels[3] = 'o';
  vowels[4] = 'u';
  vowels[5] = 'A';
  vowels[6] = 'E';
  vowels[7] = 'I';
  vowels[8] = 'O';
  vowels[9] = 'U';
  vowels[10] = '\0';

  // referenced: https://stackoverflow.com/questions/15094834/check-if-a-value-exist-in-a-array
  bool isContained = false;
  int i;
  for (i=0; i < 10; i++) {
   if(vowels[i] == c){
    isContained = true;
     }
  }
  free(vowels);
  return isContained;
}

int copy_non_vowels(int num_chars, char* in_buf, char* out_buf) {
    /*
     * Copy all the non-vowels from in_buf to out_buf.
     * num_chars indicates how many characters are in in_buf,
     * and this function should return the number of non-vowels that
     * that were copied over.
     */

     int num_non_vowels = 0;
     int i;
     for(i = 0; i < num_chars; i++) {
       if(!is_vowel(in_buf[i])) {
         out_buf[num_non_vowels] = in_buf[i];
         num_non_vowels++;
         }
     }

     return num_non_vowels;
}

void disemvowel(FILE* inputFile, FILE* outputFile) {
    /*
     * Copy all the non-vowels from inputFile to outputFile.
     * Create input and output buffers, and use fread() to repeatedly read
     * in a buffer of data, copy the non-vowels to the output buffer, and
     * use fwrite to write that out.
     */

     char* in_buf = (char*) calloc(BUF_SIZE, sizeof(char));
     char* out_buf = (char*) calloc(BUF_SIZE, sizeof(char));

     int in_len = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
     while (in_len != 0) {
       int non_vowels = copy_non_vowels(strlen(in_buf), in_buf, out_buf);
       fwrite(out_buf, sizeof(char), non_vowels, outputFile);
       in_len = fread(in_buf, sizeof(char), BUF_SIZE, inputFile);
     }

     free(in_buf);
     free(out_buf);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    FILE *outputFile;

    // Code that processes the command line arguments
    // and sets up inputFile and outputFile.

    if(argc == 1) {
      inputFile = stdin;
      outputFile = stdout;
    } else {
      if (argc == 2) {
        inputFile = fopen(argv[1], "r");
        outputFile = stdout;
      } else {
        inputFile = fopen(argv[1], "r");
        outputFile = fopen(argv[2], "w");
      }
    }

    disemvowel(inputFile, outputFile);

    return 0;
}
