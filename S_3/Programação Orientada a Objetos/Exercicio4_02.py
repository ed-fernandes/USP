import math
x = int(input("Digite um inteiro:"))
p = int(math.pow(x,0.5))
menor = x 
primo = True
i = x-1
while i>=p:
    if x%i == 0:
        primo = False
        if x/i < menor:
            menor = x/i
    i -= 1
    
if primo==True:
    print("É primo")
else:
    print("Não é primo e o menor divisor é "+ str(menor))