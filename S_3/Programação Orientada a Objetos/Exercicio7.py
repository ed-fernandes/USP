from cgi import print_form
import math
from os import X_OK
def funcao(x):
    n = float(math.pow(x,3)-math.pow(x,2)-13*x+8)
    return n
def sinal(x):
    if x >= 0:
        return 1
    else:
        return 0
a = float(input("Digite o início do intervalo:"))
b = float(input("Digite o fim do intervalo:"))
erro = float(math.pow(10,-7))
n = int(1)
while n <=1000:
    c = (a+b)/2
    if funcao(c) == 0 or (b-a) /2 < erro:
        print ("f(%.4f) = %f" %(c,funcao(c)))
        print ("%d iterações necessárias." %n)
        break
    n+=1
    if sinal(funcao(c)) == sinal(funcao(a)):
        a = c
    else:
        b = c