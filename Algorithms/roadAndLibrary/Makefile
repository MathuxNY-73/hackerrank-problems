CXX=g++
CXFLAGS=-Wc++17-extensions -Wall -stdlib=libc++ -std=c++17 -pedantic
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: main.o
	@$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper:
	@rm -rf $(EXEC)
