CC = g++
CFLAGS = -Iincludes -ansi -pedantic -std=c++11 
DBGFLAG = 

ifeq ($(MAP), 2)
DBGFLAG += -g -DMAP
else ifeq ($(MAP), 1)
DBGFLAG += -DMAP
endif

OUT = build/logger
SRC = $(wildcard data_classes/*.cpp *.cpp service/*.cpp) # Sources (.cpp)
OBJ = $(SRC:.cpp=.o)
HEADERS = $(wildcard includes/*.h)

all: $(OUT)

$(OUT): $(OBJ) ./main.o
	mkdir -p build
	$(CC) $(OBJ) ./main.o $(CFLAGS) $(DBGFLAG) -o $(OUT)

# To compile a single .cpp : g++ -c -Iincludes -ansi -pedantic -std=c++11 file.cpp

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(DBGFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(OUT) ./main.o ./build/logger
	rm -f out.dot
	rm -f temp.txt

run: all
	./$(OUT)


.PHONY: all clean run
