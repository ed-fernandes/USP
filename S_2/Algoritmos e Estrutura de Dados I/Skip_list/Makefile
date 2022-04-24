name = skiplist
headers = skiplist.h
files = main.c skiplist.c
objects = main.o skiplist.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile
