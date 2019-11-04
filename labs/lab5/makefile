CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = menu.o recursiveMethods.o main.o
SRCS = menu.cpp recursiveMethods.cpp main.cpp
HEADERS = menu.hpp recursiveMethods.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main