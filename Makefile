TARGET = main

ADT = src/ADT/arraydin/arraydin.c src/ADT/mesinkarakter/mesinkarakter.c src/ADT/mesinkata/mesinkata.c src/ADT/queue/queue.c src/ADT/queueInt/queueInt.c src/ADT/arraydinInt/arraydinInt.c src/ADT/map/map.c src/ADT/stack/stack.c src/ADT/arrayofmap/arrmap.c

Games = src/Games/DinerDash/DinerDash.c src/Games/RNG/RNG.c

all:
	gcc src/main.c src/console.c $(ADT) $(Games) -o $(TARGET)

clean:
	rm $(TARGET)