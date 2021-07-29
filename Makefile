all: compile run

compile:
	g++ *.cpp -I"SFML/include" -L"SFML\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o main.out

run:
	./main.out
