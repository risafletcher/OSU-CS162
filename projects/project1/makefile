CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = ant.o board.o getValidInt.o menu.o main.o
SRCS = ant.cpp board.cpp getValidInt.cpp menu.cpp main.cpp
HEADERS = ant.hpp board.hpp getValidInt.hpp menu.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main