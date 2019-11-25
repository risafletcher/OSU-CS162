CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = searchAndSort.o main.o
SRCS = searchAndSort.cpp main.cpp
HEADERS = searchAndSort.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main
	rm -v !("early.txt" | "middle.txt" | "end.txt" | "original.txt")