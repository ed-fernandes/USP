name = numerosgrandes
headers = bignum.h
files = main.c bignum.c
objects = main.o bignum.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile

