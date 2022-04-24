name = arvorebinaria
headers = arvore.h
files = main.c arvore.c
objects = main.o arvore.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile
