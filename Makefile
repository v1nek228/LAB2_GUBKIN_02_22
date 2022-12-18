TARGET = hello
.PHONY: all clean run
all: $(TARGET)
run:
	./a.out
clean:
	rm *.o
main.o: main.c
	gcc -c main.c
hex.o: hex.c
	gcc -c hex.c

bin.o: bin.c
	gcc -c bin.c
oct.o: oct.c
	gcc -c oct.c
dec.o: dec.c
	gcc -c dec.c
$(TARGET): main.o hex.o oct.o bin.o dec.o
	gcc main.o hex.o oct.o bin.o dec.o -std=c99 -lm
