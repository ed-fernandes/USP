import math
def funcao(x):
    return math.pow(x,3) -math.pow(x,2) -13*x + 8
def derivada_f(x):
    return 3*math.pow(x,2) -2*x -13
def newtonRaphson(x,e):
    h = float(funcao(x)/derivada_f(x))
    cont = 0
    while abs(h)>=e:
        h = funcao(x)/derivada_f(x)
        x = x - h
        cont +=1
    print("A raiz é %.4f.\n%d iterações."%(x,cont))
newtonRaphson(float(input("Digite um chute:")),math.pow(10,-7))
