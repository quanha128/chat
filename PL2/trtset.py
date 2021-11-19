def pyramid (n):
    star=1
    while (n>0):
        print(" "*(n-1), end="")
        print("*"*star)
        n-=1
        star +=2

pyramid(5)