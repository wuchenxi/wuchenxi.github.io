X=polygen(ZZ)
def kneadingpoly(lam, n):
    r=1
    x=1
    for i in xrange(n):
        if x>1/lam:
            x=2-x*lam
            r=2-r*X
        else:
            x=x*lam
            r=r*X
    return r
list_points=[]
for i in xrange(100):
    l=1.0+i*0.01
    pol=kneadingpoly(l, 40)
    list_points+=[(float(z.real()), float(z.imag()), l) for z, mul in pol.roots(ring=CDF) if abs(z)>1]
point3d(list_points)
