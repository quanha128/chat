def my_odd(xs):
    cnt = 0
    for i in xs:
        if i%2 == 1:
            cnt += 1
    return cnt

print(my_odd([2, 3, 4]))
print(my_odd([1, 3, 6]))
print(my_odd([1, 3, 5, 7]))