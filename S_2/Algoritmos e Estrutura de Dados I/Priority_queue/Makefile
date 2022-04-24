name = filapessoas
headers = pessoas.h
files = main.c pessoas.c
objects = main.o pessoas.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile
