import math
def primo (n):
    p = True
    t = int(math.pow(n,0.5))
    i = 2
    while i <= t:
        if n % i == 0:
            p = False
            break
        i+=1
    return p
n = int(input("Digite um inteiro:"))
if(primo(n)):
    print("É primo.")
else:
    while not primo(n):
        n-=1
    print("O primeiro número primo menor é "+str(n))

