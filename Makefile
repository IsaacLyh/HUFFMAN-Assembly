CC=gcc
SOURCES=main.c common.c encoder.c decoder.c
HEADERS=decoder.h encoder.h common.h
CFLAGS=-g -Wall -std=c99

all: main

main: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES) -o main

clean:
	rm -f main


encode:
	gcc -g -std=c99 decoder.c common.c test.c encoder.c -o encode_test


decode:
	gcc -g binaryToText.s decodeFile.s codeToBinary.s decodeChar.s extractBit.s common.c test.c -std=c99 encoder.c -o decode_ARM
