name = polinomio
headers = polinomios.h
files = main.c polinomios.c
objects = main.o polinomios.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile
