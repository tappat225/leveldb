# g++ -g -o leveldb_test leveldb_test.cpp ../build/libleveldb.a -lpthread -I../leveldb/include/
CC = g++
CFLAG = -g -Wall
TARGET = lbdtest
LIB = -lpthread
INC = -I../leveldb/include/
DEP = ../build/libleveldb.a

SRC = ./*.cpp
${TARGET} : ${SRC}
	${CC} ${CFLAG} ${SRC} ${DEP} -o ${TARGET} ${LIB} ${INC}

.PHONY: clean
clean:
	rm -rf ./*.o
