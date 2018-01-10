CC=g++
CFLAGS=-W -Wall -std=c++14 -pedantic
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: main.o
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: solution.h

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
