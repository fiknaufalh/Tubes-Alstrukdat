TARGET = main

all:
	gcc src/main.c src/console.c src/ADT/arraydin/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/queue/queue.c src/ADT/queueInt/queueInt.c src/ADT/arraydinInt/arraydinInt.c src/Games/DinerDash/DinerDash.c src/Games/RNG/RNG.c -o $(TARGET)

clean:
	rm $(TARGET)