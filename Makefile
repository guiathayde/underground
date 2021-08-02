ifeq ($(OS), Windows_NT)
	EXECUTABLE=.\main.exe
else
	EXECUTABLE=./main
endif

all: compile run

compile:
	g++ source/*.cpp -I"SFML/include" -I"include" -L"SFML\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -o main

run:
	$(EXECUTABLE)
