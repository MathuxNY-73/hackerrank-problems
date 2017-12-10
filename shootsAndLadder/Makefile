CC=g++
CFLAGS=-W -Wall -std=c++14 -pedantic
LDFLAGS=
EXEC=shootsAndLadder
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

shootsAndLadder: shootsAndLadder.o
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) -o $@ -c $< $(CLFAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
