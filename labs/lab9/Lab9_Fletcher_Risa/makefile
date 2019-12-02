CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = Stack.o Queue.o main.o
SRCS = Stack.cpp Queue.cpp main.cpp
HEADERS = Stack.hpp Queue.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main