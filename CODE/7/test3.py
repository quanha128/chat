n = int(input())
res = ""
if (n==1):
    print("A")
    exit()

while(n > 0):
    # print(n,"-> ", end="")
    if (n%2 != 0):
        n -= 1
        res += "A"
    # print(n,"-> ", end="")
    n /= 2
    if (n!=0): res += "B"
    # print(n)

# if (len(res) > 120): print("Failed")

res = res[::-1]
print(res)