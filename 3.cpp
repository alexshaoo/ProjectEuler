// The prime factors of 13195 are 5, 7, 13 and 29.
// 
// What is the largest prime factor of the number 600851475143 ?

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long

using namespace std;

#include<bits/stdc++.h>

using namespace std;

int main() {
	
	ll num;
	cin >> num;
	
	ll d = 2;
	
	while (d <= floor(sqrt(num))) {
	    if (num%d == 0) num /= d;
	    else d++;
	}
	
	cout << num << endl;
}