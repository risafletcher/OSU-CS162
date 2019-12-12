CXX = g++
CXXFLAGS = -std=c++0x
# CXXFLAGS += -g

OBJS = Game.o Space.o Player.o utilities.o Bathroom.o Dining.o Hall.o Library.o Reception.o Stairwell.o main.o
SRCS = Game.cpp Space.cpp Player.cpp utilities.cpp Bathroom.cpp Dining.cpp Hall.cpp Library.cpp Reception.cpp Stairwell.cpp main.cpp
HEADERS = Game.hpp Space.hpp Player.hpp utilities.hpp Bathroom.hpp Dining.hpp Hall.hpp Library.hpp Reception.hpp Stairwell.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main