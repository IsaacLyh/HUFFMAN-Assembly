//NAME : YUHANG LIAN
//PID  : A91018743

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"


//List of masks for bit munipulation;
#define mask1 0xFF000000
#define mask2 0xFF0000
#define mask3 0xFF00
#define mask4 0xFF


unsigned int *char_freqs(FILE *fp){
   /* Your code goes here*/
    //null check on pointer
    //if the pointer in null , do nothing
    if(fp == NULL){
        return NULL;
    }
    //initialize the int to store
    unsigned int* store = NULL;
    //allocate memory
    store = calloc(MAX_CHAR+1, sizeof(int));
    while(!feof(fp)){
        //if the char is in asci table , increment corresponding index
        char in = fgetc(fp);
        store[(int)in]++;
    }
    return store;
}
  

int reorder_bytes(int num){
   /* Your code goes here*/
    //get each bits from the input
    int fst = mask1&num;
    int sec = mask2&num;
    int trid = mask3&num;
    int fourth = mask4&num;
    //reverse all the bits;
    int store = ( fst >> 24) +( sec >> 8) + (trid << 8) + (fourth << 24);
    return store;
}
