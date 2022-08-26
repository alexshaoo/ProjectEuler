// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
// What is the 10 001st prime number?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

int main() {
    
    int bound;
    cin >> bound;
    
    int ind = 0;
    
    int primes[bound];
    
    for (int i = 0; ind < bound; ++i) {
        if (isPrime(i)) primes[ind++] = i;
    }
    
    cout << primes[bound-1] << "\n";
}