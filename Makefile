all: build run
build:
	gcc maze.c -lncursesw -o jelly
run:
	./jelly
clean:
	rm jelly