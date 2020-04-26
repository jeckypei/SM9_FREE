SHELL = /bin/sh
CC = gcc 
AR = ar
OBJ = build

CFLAG = -O2 -W -Wall

INCLUDE_PATH = -I.
LIB_TARGET = ./libsm9.a


SRC = $(wildcard miracl/*.c) $(wildcard sm9/*.c )
SOURCES=$(notdir $(SRC))
SM9_OBJ = $(patsubst %.c,%.o, $(SOURCES))

all :  test 

$(SM9_OBJ): $(SRC)
	$(CC) $(CFLAG) $(INCLUDE_PATH) -c $(SRC)

$(LIB_TARGET) : $(SM9_OBJ)
	$(AR) cq $@ $^

test: SM9Test.c
	$(CC) -c SM9Test.c -o SM9Test.o 
	$(CC)  SM9Test.o $(SM9_OBJ) -o test 
	rm -f ./*.o

clean:
	rm -f ./*.o
	rm -f $(LIB_TARGET)
	rm -f test
