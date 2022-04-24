import math
def bhaskara(a, b, c):
    delta = b*b - 4 * a * c
    if delta >= 0:
        x1 = (-b + math.pow(delta,0.5))/(2*a)
        x2 = (-b - math.pow(delta,0.5))/(2*a)
        print("Tem duas raizes "+str(x1)+" e "+str(x2))
    else:
        print("Não tem raizes")
    return
def lerNum():
    while True:
        try:
            x = float(input())
            break
        except ValueError:
            print("Não é número, digite novamente:")
    return x
print("Digite o primeiro coeficiente:")
coef_a = lerNum()
print("Digite o segundo coeficiente:")
coef_b = lerNum()
print("Digite o terceiro coeficiente:")
coef_c = lerNum()
bhaskara(coef_a,coef_b,coef_c)
