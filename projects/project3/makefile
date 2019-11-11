CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -g

OBJS = Game.o Character.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o Vampire.o main.o
SRCS = Game.cpp Character.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Vampire.cpp main.cpp
HEADERS = Game.hpp Character.hpp Barbarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Vampire.hpp

main: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o main -ggdb

clean:
	rm main