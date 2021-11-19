def isLeapYear(year):
    byear = 0
    offset = int( year[1:len(year)] )
    if (year[0] == 'M'):
        byear = 1868 + offset
        if (byear > 1912): return 0
    elif (year[0] == 'T'):
        byear = 1912 + offset
        if (byear > 1926): return 0
    elif (year[0] == 'S'):
        byear = 1926 + offset
        if (byear > 1989): return 0
    elif (year[0] == 'H'):
        byear = 1989 + offset
        if (byear > 2019): return 0
    else:
        byear = 2019 + offset
        if (byear > 2030): return 0

    print(byear)

    if (byear % 4 ==0):
        if (byear % 100 == 0):
            if (byear % 400 ==0):
                return 1
            else: return 0
        else: return 1
    else: return 1

print(isLeapYear("H033"))