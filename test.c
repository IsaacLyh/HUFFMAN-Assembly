#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "common.h"
#include "encoder.h"
#include "decoder.h"

int printBit(char in){
    int c,k;
        for (c = 7; c >= 0; c--)
            {
                    k = in >> c;
                            
                      if (k & 1)
                                                printf("1");
                                                        else
                                                                    printf("0");
                                                                        }
                                                                            
                                                                                printf("\n");
                                                                                    
                                                                                        return -1;
                                                                                      }


int main(int argc, char** argv){
    createReverseMapping();
    //encodeFile(argv[1],argv[2],argv[1],3);
    /*FILE* in = fopen(argv[1],"r");
    FILE* out = fopen(argv[2],"w");
    codeToBinary(in,out,3);
    fclose(in);
    fclose(out);
    FILE* in2 = fopen(argv[2],"r");
    FILE* out2 = fopen(argv[1],"w");
    binaryToText(in2,out2);
    */
    // char f = 'f';
    //printBit(f);
   // printf("%d\n",extractBit(f,5));
   // implantBit('c',0,2);
    //FILE* in2 = fopen(argv[2],"r");
    //FILE* out2 = fopen(argv[3],"w");
   // codeToBinary(in2,out2,2);
    
    
    //binaryToCode(in2,out2,2);
    //encodeFile(argv[1],argv[2],argv[3],2);
    //char arr[6] = {1,0,1,0,0,0};
    //printf("%c",decodeChar(arr));
    //char c = '0';
    //printBit(c);
    //printf("bit = %d",extractBit(c,4));
    decodeFile(argv[1],argv[2],argv[3],2);
    //textToBinary(in,out);
    //fclose(in);
    //fclose(out);
}



