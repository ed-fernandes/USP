name = palavrasfrequentes
headers = palavras.h
files = main.c palavras.c
objects = main.o palavras.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile
