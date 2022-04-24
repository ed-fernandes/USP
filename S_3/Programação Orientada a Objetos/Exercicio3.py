x = int(input("Digite um inteiro:"))
y = x
while y > 0:
    x = y
    while x > 0:
        print("*", end="")
        x-=1
    print("")
    y-=1