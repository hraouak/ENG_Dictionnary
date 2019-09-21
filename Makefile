CC=gcc
EXEC=executable

all: $(EXEC)

executable: projet.o main.o
	$(CC) -o executable projet.o main.o -g

projet.o: projet.c
	$(CC) -c projet.c
	
main.o: main.c projet.h
	$(CC) -c main.c

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)