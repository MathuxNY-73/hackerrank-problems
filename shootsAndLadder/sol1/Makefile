CXX=g++
CXFLAGS=-W -Wall -std=c++14 -pedantic
LDFLAGS=
EXEC=shootsAndLadder
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

shootsAndLadder: shootsAndLadder.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
