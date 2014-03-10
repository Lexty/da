MODE=DEBUG

CC=gcc
CFLAGS=-pedantic -Wall -std=c99 -Werror -Wno-sign-compare -lm
LINK=$(CC)

EXEC=$(shell basename `pwd`)
TARGET=build/$(EXEC).a

SOURCES=$(wildcard src/*.c)
#OBJECTS=$(SOURCES:%.c=%.o)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

.SUFFIXES: .c .o
BULDDEPS=
CLEANDEPS=
ifeq ($(MODE),DEBUG)
CFLAGS+= -g
BUILDDEPS+=tests testscheck
CLEANDEPS+=testsclean
endif

all: $(TARGET) $(BUILDDEPS)

$(TARGET): build $(OBJECTS)
	$(LINK) -o $(TARGET) $(patsubst src/%,build/%,$(OBJECTS))
	cp $(TARGET) $(EXEC)

$(OBJECTS): $(SOURCES)

.c.o:
	$(CC) $(CFLAGS) -c -o $(patsubst src/%,build/%,$@) $<

build:
	@mkdir -p build


tests:
	cd tests; make

testscheck:
	cd tests; ./check.sh

testsclean:
	cd tests; make clean


clean: $(CLEANDEPS)
	rm -rf build
	rm $(EXEC)

.PHONY: all clean tests
