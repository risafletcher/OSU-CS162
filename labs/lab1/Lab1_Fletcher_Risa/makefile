CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = readMatrix.o determinant.o main.o
SRCS = readMatrix.cpp determinant.cpp main.cpp
HEADERS = readMatrix.hpp determinant.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main