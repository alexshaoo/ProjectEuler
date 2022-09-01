// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//
// What is the 10 001st prime number?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	
	int bound;
	cin >> bound;
    
  // simply brute force solution
  for (int i = 3; i < bound; ++i) {
  	for (int j = 4; j < bound; ++j) {
  		for (int k = 5; k < bound; ++k) {
  			if (i*i+j*j == k*k && i+j+k == bound) {
  				cout << i*j*k << "\n";
  				return 0;
  			}
  		}
  	}
  }
}