CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = Queue.o Menu.o main.o
SRCS = Queue.cpp Menu.cpp main.cpp
HEADERS = Queue.hpp Menu.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main