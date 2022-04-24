n = float(input("Digite um número:"))
menor = n
maior = n
while True:
    if n == 0:
        break
    if n <= menor:
        menor = n
    elif n>= maior:
        maior = n
    n = float(input("Digite um número:"))
print("O menor digitado foi "+str(menor)+" e o maior "+str(maior))
