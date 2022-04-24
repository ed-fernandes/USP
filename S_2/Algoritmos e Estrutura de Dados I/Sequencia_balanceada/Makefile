name = ex5
headers = balanceado.h
files = main.c balanceado.c
objects = main.o balanceado.o

$(headers): $(objects)

all : $(objects)
	gcc -c $(files) -g
	gcc -o $(name) $(objects) -g


run : all
	./$(name)

zip :
	zip -r $(name) $(headers) $(files) Makefile

