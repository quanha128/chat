def solution(A, B, C):
    def minus1(i): return i-1
    def diverse(str):
        if str == "": return False
        if len(str) < 3:
            return False
        for i in range(len(str)-2):
            if str[i] == str[i+1]:
                if str[i+1] == str[i+2]:
                    return True
        return False
    res = ""
    skipA = False
    skipB = False
    skipC = False
    while(A>0 or B>0 or C>0):
        if (A>0):
            if skipA: pass
            elif diverse(res+"a"):
                skipB = False
                skipC = False
                skipA = True
                continue
            elif minus1(A)==0:
                skipB = False
                skipC = False
                skipA = True
                res+='a'
                A -= 1
                continue
            else:
                res += "a"
                A -= 1
                skipB= True
                skipC= True
                continue
        if (B>0):
            if skipB: pass
            elif diverse(res+"b"):
                skipA = False
                skipC = False
                skipB = True
                continue
            elif minus1(B)==0:
                skipA = False
                skipC = False
                skipB = True
                res+='b'
                B -= 1
                continue
            else:
                res += "b"
                B -= 1
                skipA = True
                skipC = True
                continue
        if (C>0):
            if skipC: pass
            elif diverse(res+"c"):
                skipA = False
                skipB = False
                skipC = True
                continue
            elif minus1(C)==0:
                skipA = False
                skipB = False
                skipC = True
                res+='c'
                C -= 1
                continue
            else:
                res += "c"
                C -= 1
                skipA = True
                skipB = True
                continue
    return res


# def diverse(str):
#     for i in range(len(str)-2):
#         if str[i] == str[i+1]:
#             if str[i+1] == str[i+2]:
#                 return False
#     return True

# print(diverse("aabbaaacc"))

print(solution(1,1,7))