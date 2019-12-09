CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = record.o main.o
SRCS = record.cpp main.cpp
HEADERS = record.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main