Battleship: main.o Executive.o Ships.o Board.o Ai.o
	g++ -std=gnu++11 -g -Wall main.o Executive.o Ai.o Ships.o Board.o -o Battleship

main.o: main.cpp Executive.cpp Executive.h
	g++ -std=gnu++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp Executive.h Ai.cpp Ai.h Ships.cpp Ships.h Board.cpp Board.h
	g++ -std=gnu++11 -g -Wall -c Executive.cpp

Ships.o: Ships.cpp Ships.h
	g++ -std=gnu++11 -g -Wall -c Ships.cpp

Board.o: Board.cpp Board.h
	g++ -std=gnu++11 -g -Wall -c Board.cpp

Ai.o: Ai.cpp Ai.h
	g++ -std=gnu++11 -g -Wall -c Ai.cpp

clean:
	rm *.o Battleship
