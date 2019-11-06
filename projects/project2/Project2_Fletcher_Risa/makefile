CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = Animal.o Penguin.o Tiger.o Turtle.o Zoo.o Game.o main.o
SRCS = Animal.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp Game.cpp main.cpp
HEADERS = Animal.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp Game.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main