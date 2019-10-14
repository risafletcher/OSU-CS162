CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = outputLetters.o countLetters.o main.o
SRCS = outputLetters.cpp countLetters.cpp main.cpp
HEADERS = outputLetters.hpp countLetters.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main