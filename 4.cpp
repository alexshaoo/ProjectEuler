// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
// 
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

bool isPalindrome(int num) {
	string s = to_string(num);
	return s == string(s.rbegin(), s.rend());
}

int main() {
	int m = 0;
	for (int i = 999; i >= 100; --i) {
		for (int j = 999; j >= i; --j) {
			int p = i*j;
			if (isPalindrome(p)) {
				m = max(m, p);
			}
		}
	}
	
	cout << m << "\n";
}