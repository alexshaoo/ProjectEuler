#include <bits/stdc++.h>

using namespace std;

const int MAX = 4e6;

int main() {
	
	int sum = 0, temp, a = 2, b = 3;
	
	while (a < MAX) {
		sum += a;
		temp = a+b;
		a += (2*b);
		b = a + temp;
	}
	
	cout << sum << "\n";
}