def getval(varname, locals, globals):
    if varname in locals:
        return locals[varname]
    elif varname in globals:
        return globals[varname]

def foo(x):
    y=x+1
    print(x, getval('x', locals(), globals()))
    print(y, getval('y', locals(), globals()))
    print(z, getval('z', locals(), globals()))

z = 100
# foo(z+1)

def Count():
    _cnt = 0

    def incr():
        nonlocal _cnt
        _cnt += 1
        return _cnt
    def get():
        nonlocal _cnt
        return _cnt
    def reset():
        nonlocal _cnt
        _cnt = 0