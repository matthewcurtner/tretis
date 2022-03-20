build:
	g++ -c main.cpp
	g++ main.o -o main -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm main.o
	rm main
