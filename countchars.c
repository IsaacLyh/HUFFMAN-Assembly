//NAME: YUHANG LIAN
//PID : A91018743

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"


int main(int argc, char** argv){
     /* Your main code for counting characters in a file goes here */
     /* To write your output to file use the following statement:
      * fprintf(fp,"%c - %d \n", c, count);
      * fp: file pointer
      * c: Character symbol
      * count: Character count
      */
    //OPEN 2 FILES
    FILE* in = fopen(argv[1],"r");
    FILE* out = fopen(argv[2],"w");
    //null check
    if(in == NULL || out == NULL){
        return -1;
    }
    //write in frequency
    unsigned int* store = char_freqs(in);
    for(int i = 0; i < 256;i++){
        if(store[i] != 0){
            char c = (char)i;
            fprintf(out,"%c - %d \n",c,store[i]);
        }
    }
    //close file
    fclose(in);
    fclose(out);
}
