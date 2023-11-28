CXX=g++
CC=g++

OBJ=
BIN=main

all: ${BIN}

${BIN}: main.o ${OBJ}

clean:
	${RM} ${OBJ} ${BIN} main.o

check: ${BIN}
	./${BIN} input

.PHONY: all clean check
