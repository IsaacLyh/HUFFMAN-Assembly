/**
 * ALL IMPLEMENTATIONS AND HELPER FUNCTIONS FOR DECODER WILL BE IN THIS FILE.
 */
//NAME : YUHANG LIAN
//PID  : A91018743
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "decoder.h"


#define mask1 0b1
#define mask2 0b10
#define mask3 0b100
#define mask4 0b1000
#define mask5 0b10000
#define mask6 0b100000
#define mask7 0b1000000
#define mask8 0b10000000




/**
 * Takes a char c and int index as input. 
 * Extracts the bit at the input index from the char c. The 0 index
 * refers to the LSB, so for example, index 2 should extract the 3rd
 * least significant bit.
 *
 * @param c the char to extract a bit from
 * @param index the index of the bit to extract
 * @returns the value of the bit at index in c
 */
int extractBit(char c, int index){
    // TODO Implement me!
    //USE BIT SHIFT TO GET INDEX AT REQUIRED POS
    int returnVal = 100;
    //THE FOLLOWING CODE WILL USE DIFFERENT MASK DEPENDING ON SITUATION
    
    if(index == 0){
        returnVal = c&mask1;
    }
    else if(index == 1){
        returnVal = c&mask2;
        returnVal = returnVal >> index;
    }
    else if(index == 2){
        returnVal = c&mask3;
        returnVal = returnVal >> index;
    }
    else if(index == 3){
        returnVal = c&mask4;
        returnVal = returnVal >> index;
    }
    else if(index == 4){
        returnVal = c&mask5;
        returnVal = returnVal >> index;
    }
    else if(index == 5){
        returnVal = c&mask6;
        returnVal = returnVal >> index;
    }
    else if(index == 6){
        returnVal = c&mask7;
        returnVal = returnVal >> index;//USE MASKS TO GET REQUIRED BITS
    }
    else if(index == 7){
        returnVal = c&mask8;
        returnVal = returnVal >> index;
    }
    return returnVal;
}

/**
 * Takes a 6 character array b as input and returns the corresponding
 * char from MAPPING that is indexed by the binary ASCII string b.
 * For example, if b = "010101", then the char that is mapped to it is 
 * in MAPPING, index 1*16 + 1*4 + 1*1 = 21.
 *
 * @param b a pointer to a 6 character array, with ASCII '1's and '0's
 * @returns the corresponding character from MAPPING
 */
char decodeChar(char *b){
    // TODO Implement me!
    if(b == NULL){
        return '0';
    }
    int val = b[0] * 32 + b[1] * 16 + b[2] * 8 + b[3] * 4 + b[4] * 2 + b[5];
    char returnVal = MAPPING[val];
    return returnVal;
}


/**
 * Takes a FILE handle in as input (corresponding to
 * an encoded file) and reads the file, char by char. The
 * bit at the input index of each char is extracted (by calling
 * extractBit). The least significant bit is in index 0.
 *
 * For each character, if the extracted bit is 0, output ASCII '0' to
 * the output file. If the extracted bit is 1, output ASCII
 * '1' to the output file.
 *
 * @param in the input file handle to read from
 * @param out the output file to write the extracted ASCII binary into
 * @param index the index of the bit to extract from each char
*/
void codeToBinary(FILE *in, FILE *out, int index){
    if(in == NULL||out == NULL){
        return;
    }
    while(!feof(in)){
        char read = fgetc(in);  //THIS WILL READ IN BITS
        int decoded = extractBit(read,index);
        if(decoded == 0){
            fprintf(out,"%c",'0');//CHECK AND OUT PUT
        }
        else if(decoded == 1){
            fprintf(out,"%c",'1');
        }
    }
}

/**
 * Takes a FILE handle in as input (corresponding to a
 * "binary" decoded file) and reads the file, 6 chars at a
 * time. Each 6 chars (all ASCII 0's and 1's) should be read into a
 * char array and decoded into its corresponding char (by calling
 * decodeChar). The resulting chars would be output to the FILE handle
 * pointed to by out.
 *
 * @param in the input file, encoded as ASCII '1's and '0's
 * @Param out the decoded output file (ASCII)
*/
void binaryToText(FILE *in, FILE *out){
    // TODO Implement me!
    if(in==NULL||out==NULL){
        return;
    }
    char* array;
    array = calloc(6,sizeof(char));
    int counter = 0;
    while(!feof(in)){
        if(counter != 6){
            char inC = fgetc(in);
            if(inC == '1')
            {
                array[counter] = 1;
            }//CONVERT BINARY TO TEXT BASED ON THE VALUE READ
            else if(inC == '0'){
                array[counter] = 0;
            }
            counter++;
        }//OUT PUT THE CHAR
        else{
            char outC = decodeChar(array);
            fprintf(out,"%c",outC);
            counter = 0;
        }
    }
}

/**
 * Reads in a file from the specified input path and outputs a a binary decoding to
 * specified bin path and a fully decoded version to specified output path.
 * This should simply open the necessary files, call the above helper functions
 * in the correct sequence, and close the necessary files.
 *
 * @param input the path to the input file
 * @param bin the path to the decoded ASCII binary output file
 * @param output the path to the decoded output file
 * @param index The index of the bit from which binary values should be extracted
 */
void decodeFile(char* input, char* bin, char* output, int index){
    // TODO Implement me!
    FILE* in = fopen(input,"r");
    FILE* out = fopen(bin,"w");
    codeToBinary(in,out,index);//WIRITE ALL THE METHOD INTO A SINGLE FUNCTION
    fclose(in);//CLOSE THE FILE THAT ARE USELESS
    fclose(out);
    FILE* in2 = fopen(bin,"r");
    FILE* out2= fopen(output,"w");
    binaryToText(in2,out2);
    fclose(in2);
    fclose(out2);
}
