
# Simple makefile

CC = g++ -std=c++17

libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

defualt: sfml-app clean

main.o: main.cc
	$(CC)++ -c main.cc

sfml-app: main.o
	$(CC) main.o -o sfml-app $(libs)

run: sfml-app
	./sfml-app

clean:
	rm -rf *.o **/*.o

clean-all: clean
	rm -rf sfml-app *.out *.exe
