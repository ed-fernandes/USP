#Eduardo Fernandes
#N_USP 12681733
import numpy as np
import random
while True:
    try:
        n = int(input("Digite um valor inteiro maior que 0:"))
        if n > 0:
            break
        else:
            print("Erro! Tente novamente.")

    except ValueError:
        print("Erro! Tente novamente.")
while True:
    try:
        p = float(input("Digite um valor entre 0 e 1:"))
        if(p > 0 and p < 1):
            break
        else:
          print("Erro! Tente novamente.")  
    except ValueError:
        print("Erro! Tente novamente.")
m = np.zeros((n,n), dtype=int)  
for i in range (1,n):
    for j in range(i):
        x = random.random()
        if x > p :
            m[i][j] = 1
            m[j][i] = 1
       
print(m)
