CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = Game.o Losers.o Lineup.o Character.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Vampire.o main.o
SRCS = Game.cpp Losers.cpp Lineup.cpp Character.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Vampire.cpp main.cpp
HEADERS = Game.hpp Losers.hpp Lineup.hpp Character.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Vampire.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main