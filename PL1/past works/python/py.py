a = float(input("Enter the decimal number you want to convert: "))
b = int(input("Enter the base you want to convert to (b): "))
l=''
num=int(a//1)
while True:
    q=num//b
    l+=str(num%b)
    num=q
    if q==0:
        l=l[::-1]
        if a%(a//1)!=0:
            l+='.'
        break

dec=a%(a//1)
if dec!=0:
  while True:
    m=dec*b
    l+=str(int(m//1))
    if m>=1:
        dec=m%(m//1)
    elif m<1:
        dec=m
    if dec==0:
        break
if a%(a//1)!=0:
    print("The base-"+str(b),"equivalent of",a,"is",l)
if a%(a//1)==0:
    print("The base-"+str(b),"equivalent of",int(a),"is",l)