CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = Game.o Die.o getValidInt.o LoadedDie.o main.o Player.o
SRCS = Game.cpp Die.cpp getValidInt.cpp LoadedDie.cpp main.cpp Player.cpp
HEADERS = Game.hpp Die.hpp getValidInt.hpp LoadedDie.hpp Player.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main