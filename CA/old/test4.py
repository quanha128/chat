class Cuboid:
    def __init__(self, h, w, d):
        self.height = h
        self.weight = w
        self.depth = d
    def volume(self):
        return self.height*self.weight*self.depth

c1 = Cuboid(60.0, 40.0, 30.0)
c2 = Cuboid(5.0, 3.6, 2.0)
print(c1.volume())
print(c2.volume())