CC=gcc
CFLAGS=-pedantic -std=c99 -Wno-sign-compare -lm -g
LINK=$(CC)

EXEC=$(shell basename `pwd`)
TARGET=build/$(EXEC).a

SOURCES=$(wildcard src/*.c)
#OBJECTS=$(SOURCES:%.c=%.o)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET): build $(OBJECTS)
	$(LINK) -o $(TARGET) $(patsubst src/%,build/%,$(OBJECTS))
	cp $(TARGET) $(EXEC)

$(OBJECTS): $(SOURCES)

.c.o:
	$(CC) $(CFLAGS) -c -o $(patsubst src/%,build/%,$@) $<

build:
	@mkdir -p build

clean:
	rm -rf build
	rm $(EXEC)

.PHONY: all clean tests
