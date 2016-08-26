CC=g++
CFLAGS=-Wall -Werror -O3 -std=c++11 -g -Wl,--no-as-needed -ldl -rdynamic -fstack-protector-all

LIBS=-pthread -lprotobuf

INCLUDE_LIBS=-Iprotos/generated/ -Iinclude/

S_SOURCES=protos/generated/*cc src/*cc
S_OBJECTS=$(S_SOURCES:.cc=.o)
S_EXECUTABLE=accf.app

.PHONY: all clean test prep

all: $(S_SOURCES) $(S_EXECUTABLE)

$(S_EXECUTABLE): $(S_OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDE_LIBS) $(INCLUDE) $(S_OBJECTS) -o $@ $(LIBS)
