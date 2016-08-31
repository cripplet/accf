CC=g++
CFLAGS=-Wall -Werror -O3 -std=c++11 -g -Wl,--no-as-needed -ldl -rdynamic -fstack-protector-all

LIBS=-lpthread -lprotobuf

INCLUDE_LIBS=-Iprotos/generated/ -Iinclude/

S_SOURCES=protos/generated/*cc src/*cc
S_OBJECTS=$(S_SOURCES:.cc=.o)
S_EXECUTABLE=accf.app

T_SOURCES=protos/generated/*cc src/*cc tests/*cc
T_OBJECTS=$(T_SOURCES:.cc=.o)
T_EXECUTABLE=test.app

.PHONY: all clean test prep

all: clean $(S_SOURCES) $(S_EXECUTABLE)

$(S_EXECUTABLE): $(S_OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDE_LIBS) $(INCLUDE) $(S_OBJECTS) -o $@ $(LIBS)

$(T_EXECUTABLE): $(T_OBJECTS)
	@$(CC) $(CFLAGS) -D _NO_MAIN $(INCLUDE_LIBS) $(INCLUDE) $(T_OBJECTS) -o $@ $(LIBS)

_EXEC?=false
test: clean $(S_EXECUTABLE) $(T_EXECUTABLE) prep
	@if [ "$(_EXEC)" = "true" ]; then \
		ulimit -c unlimited && valgrind -v --leak-check=full --show-leak-kinds=all ./$(T_EXECUTABLE) 2>&1 | tee results.log; \
	fi

clean:
	@rm -f $(S_EXECUTABLE) $(T_EXECUTABLE) *.o *.log core
