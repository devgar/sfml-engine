
# Simple makefile

CC = g++ -std=c++11

libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

defualt: sceneTest.out clean

o:
	$(CC) -c *.cc
	rm -f animationTest.o

sceneTest.out: o
	$(CC) *.o -o sceneTest.out $(libs)

run: sceneTest.out
	./sceneTest.out

clean:
	rm -rf *.o **/*.o

clean-all: clean
	rm -rf *.out *.exe
