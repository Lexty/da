CC=gcc
#CFLAGS=-pedantic -Wall -std=c99 -Werror -Wno-sign-compare -lm -g
CFLAGS=-pedantic -std=c99 -Werror -Wno-sign-compare -lm -g
SRC=counting-sort.c
OUT=counting-sort

all:
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -rf $(OUT)
	rm -f *.o
	rm -f *~
