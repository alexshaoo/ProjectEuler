// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// 
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ull inp, n = 1;
	cin >> inp;
	for (ull i = 2; i <= inp; ++i) n = lcm(n, i);
	cout << n << "\n";
}