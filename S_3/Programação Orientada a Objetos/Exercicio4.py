x = int(input("Digite um inteiro:"))
y = x
j = x
while y > 0:
    x = y
    k = j-x
    while k > 0:
        print(" ",end="")
        k -=1
    while x > 0:
        print("*", end="")
        x-=1
    print("")
    y-=1