import math

def gen_primes():
    """ Generate an infinite sequence of prime numbers.
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}

    # The running integer that's checked for primeness
    q = 2

    while True:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            #
            yield q
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next
            # multiples of its witnesses to prepare for larger
            # numbers
            #
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]

        q += 1


# primes = gen_primes()

# print (primes)

x = set()
y = 0
a = gen_primes()
while y < 10000:
  x |= set([a.next()])
  y += 1

# print(x)

# print "x contains {:,d} primes".format(len(x))
# print "largest is {:,d}".format(sorted(x)[-1])

allPrimes = []

for i in sorted(x):
    allPrimes.append(i)

# print(allPrimes)

divideBy = 1.0
constant = 0.0
for i in range(0, 9999):
    # print((allPrimes[i] - 1), divideBy)
    constant = constant + ( (allPrimes[i] - 1.0) / divideBy)
    divideBy = divideBy * allPrimes[i]


# print("{0:.100f}".format(constant))
# print(1.0/2.0)

def getPrimes(fn):
    return math.floor(fn) * (fn - math.floor(fn) + 1)

allPrimes2 = []

for i in range(0, 20):
    allPrimes2.append(math.floor(constant))
    constant = getPrimes(constant)

print(allPrimes2)
