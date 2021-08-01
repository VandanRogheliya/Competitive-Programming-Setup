

from sympy import divisors, floor, gcd

def a(n): return n*max([(floor((d - 1 - gcd(d, 4))/4) + 1)/d for d in divisors(n)])

print([a(n) for n in range(2, 101)]) # Indranil Ghosh, Jul 08 2017 