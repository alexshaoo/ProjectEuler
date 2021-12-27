# from a very good observation made during testing
from functools import reduce
primes = [i for i in range(2, 1001) if all(i%j != 0 for j in range(2, int(i**0.5)+1))]
print([reduce((lambda a, b : a*b), primes[:i]) for i in range(1, 10) if reduce((lambda a, b : a*b), primes[:i]) < 1000000][-1])