// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int calcSum(int n) {
	return n * (n+1) / 2;
}

int calcSquaredSum(int n) {
	return n * (n+1) * (2*n+1) / 6;
}

int main() {
	ull n, s = 0;
	cin >> n;
	
	s = pow(calcSum(n), 2);
	s -= calcSquaredSum(n);
	
	cout << s << "\n";
}