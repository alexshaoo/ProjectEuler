// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// 
// Find the sum of all the primes below two million.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

// only tests 
bool isPrime(int num) {
	if (num <= 1) return false;
	if (num == 2 || num == 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;
	for (int i = 5; i*i <= num; i += 6) {
		if (num % i == 0 || num % (i+2) == 0) return false;
	}
	return true;
}

int main() {
	
	int bound;
	cin >> bound;
	
	ll s = 2;
	
	for (int i = 3; i < bound; i += 2) if (isPrime(i)) s += i;
	
	cout << s << "\n";
}