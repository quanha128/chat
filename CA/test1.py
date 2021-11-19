def my_check(lst):
    str_len = len(lst[0])
    for i in range(0, len(lst)):
        if len(lst[i]) != str_len:
            return False
    return True

print(my_check(['apple', 'grape', 'juice']))
print(my_check(['apple', 'grape', 'banana']))