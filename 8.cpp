// The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
// Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

ull longest(string n, int c) {
	if (n.length() < c) return 0;
	
	ll p = 1;
	for (int i = 0; i < c; ++i) p *= (n[i]-'0');
	
	ull m = p;
	for (int i = 0; i+c < n.length(); ++i) {
		p = p * (n[i+c]-'0') / (n[i]-'0');
		if (p > m) m = p;
	}
	
	return m;
}

int main() {
	string num;
	int consec;
	cin >> num;
	cin >> consec;
	
	ull m = 0;
	string temp = "";
	
	for (int i = 0; i < num.length(); ++i) {
		if (num[i] != '0') temp += num[i];
		else {
			m = max(m, longest(temp, consec));
			temp = "";
		}
		m = max(m, longest(temp, consec));
	}
	
	cout << m << "\n";
}