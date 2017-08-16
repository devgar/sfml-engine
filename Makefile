
# Simple makefile

libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

defualt: run

main.o: main.cc
	g++ -c main.cc

sfml-app: main.o
	g++ main.o -o sfml-app $(libs)

run : sfml-app
	./sfml-app

clean :
	rm -rf *.o sfml-app
