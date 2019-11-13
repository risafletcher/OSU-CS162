CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = LinkedList.o Menu.o Node.o main.o
SRCS = LinkedList.cpp Menu.cpp Node.cpp main.cpp
HEADERS = LinkedList.hpp Menu.hpp Node.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main