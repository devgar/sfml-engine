
# Simple makefile

CC = g++ -std=c++17

libs = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

defualt: sfml-app clean

main.o: main.cc
	$(CC)++ -c main.cc

sfml-app.out: main.o
	$(CC) main.o -o sfml-app.out $(libs)

run: sfml-app.out
	./sfml-app.out

clean:
	rm -rf *.o **/*.o

clean-all: clean
	rm -rf sfml-app *.out *.exe
