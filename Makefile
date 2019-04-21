CC=g++
CFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -std=c++11
SOURCES=src/tic-tac-toe.cpp
EXECUTABLE=bin/tic-tac-toe.exe

$(EXECUTABLE): $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(CFLAGS)


.PHONY: clean
clean:
	rm -rf build/*.o bin/*.exe