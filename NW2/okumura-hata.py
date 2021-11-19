import math

def okuhata(f, hb, hm, d, city):
    if city == 'small': ahm = (1.1* math.log10(f)-0.7)*hm - (1.56*math.log10(f)-0.8)
    elif city =='large':
        if f < 400: ahm = 8.29*(math.log10(1.54*hm))**2 - 1.1
        elif f >= 400: ahm = 3.2*(math.log10(11.75*hm))**2 - 4.97
    return 69.55 + 26.16 * math.log10(f) - 13.82 * math.log10(hb) + (44.9 - 6.55*math.log10(hb))*math.log10(d) - ahm

