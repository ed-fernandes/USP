chute = float(input("Digite um número que deseja calcular a raiz quadrada:"))
precisao = 0.00000001
b = chute
a = 1
while((b-a) >= precisao):
    b = (a+b)/2
    a = chute/b
print("A raiz é aproximadamente "+str(b))
