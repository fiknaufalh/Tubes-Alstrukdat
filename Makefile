TARGET = main

all:
	gcc src/main.c src/console.c src/ADT/arraydin/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/queue/queue.c -o $(TARGET)

clean:
	rm $(TARGET)