
# Simple makefile

CC = g++ -std=c++17

libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

defualt: sceneTest clean

o:
	$(CC) -c *.cc
	rm -f animationTest.o

sceneTest: o
	$(CC) *.o -o sceneTest $(libs)

run: sceneTest
	./sceneTest

clean:
	rm -rf *.o **/*.o

clean-all: clean
	rm -rf sceneTest *.out *.exe
