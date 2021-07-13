all: compile run

compile:
	g++ main.cpp -I"SFML/include" -L"SFML\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o main

run:
	.\main.exe