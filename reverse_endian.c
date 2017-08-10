//NAME : YUHANG LIAN
//PID  : A91018743

#include <stdio.h>
#include <stdlib.h>
#include "warmup.h"

int main(int argc, char** argv){
     /* Your main code for reversing endian-ness goes here*/
    //open the file and find length;
    FILE* count;
    count = fopen(argv[1],"r");
    //null check
    if(count == NULL){
        return -1;
    }
    int y;
    //count length
    int counter=0;
    while(!feof(count)){
        fread(&y, 1,1,count);
        counter++;
    }
    fclose(count);
    FILE* in;
    FILE* out;
    in = fopen(argv[1],"r");
    out = fopen(argv[2], "w");
    //reopen all the files
    if(in == NULL || out == NULL){
        return -1;
    }
    int x;
    //write and reverse bits
    while(counter>=4){
        counter = counter -4;
        fread(&x, 4,1,in);
        int outPut = reorder_bytes(x);
        printf("%d \n",counter);
        fwrite(&outPut,4,1,out);
    }
    fclose(in);
    fclose(out);
    
}
