#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const ull mod = 1e9+7;
const int MAXN = 1e5+5;

vector<int> prime, lpf;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	
	for (int x = 3; x <= n; x += 2) {
	  if (lpf[x] == 2) prime.push_back(lpf[x] = x);
	  for (ull i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i) lpf[prime[i] * x] = prime[i];
	}
}

ll addMOD(ll a, ll b, const ll MOD) {
  return (a + b) % MOD;
}

ll mulMOD(ll a, ll b, const ll MOD) {
  // if (double(a) * b <= 1e18) return (a * b) % MOD;
  
  ll res = 0;
  for (a %= MOD; b > 0; a <<= 1, b >>= 1) {
    if (a >= MOD) a -= MOD;
    if (b & 1) {
      res += a;
      if (res >= MOD) res -= MOD;
    }
  }

  return res;
}

ll powMOD(ll x, ll n, const ll MOD) {
  ll res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = mulMOD(res, x, MOD);
    x = mulMOD(x, x, MOD);
  }
  return res;
}

bool mr_test(ll n, int a, ll d, int s) {
  ll x = powMOD(a, d, n);
  if (x == 1 || x == n - 1) return false;
  for (int r = 1; r < s; ++r) {
    x = mulMOD(x, x, n);
    if (x == n - 1) return false;
  }
  return true;
}

bool miller_rabin(ll n, int k = 5) {
  if (n < 4) return n == 2 || n == 3;
  if (n % 2 == 0 || n % 3 == 0) return false;

  int s = __builtin_ctz(n - 1);
  ll d = (n - 1) >> s;
  for (int it = 1; it <= 5; ++it) {
    int a = 2 + rand() % (n - 3);
    if (mr_test(n, a, d, s)) return false;
  }

  return true;
}

bool isPrime(ll n) {
  if (n < 2) return false;    
  if (n < (ll)lpf.size()) return lpf[n] == n;
  return miller_rabin(n);
}

ll any_divisor_of(ll n) {
  if (n <= 1) return 1;
  if (n < (ll)lpf.size()) return lpf[n];
  if (isPrime(n)) return n;

  ll d = n;
  for (ll c = 2; d == n; ++c) {    
    ll x = 2, y = 2, i = 2, k = 2;
    while (true) {
      x = (mulMOD(x, x, n) + c);
      if (x >= n)	x -= n;
      d = __gcd(abs(x - y), n);
      if (d > 1 && n % d == 0) break;
      if (i++ == k) y = x, k <<= 1;
    }
  }

  return d;
}

bool isSquarePrime(ll n) {
  ll t = round(sqrt(n));
  return (t * t == n && isPrime(t));
}

bool isCubePrime(ll n) {
  ll t = round(cbrt(n));
  return (t * t * t == n && isPrime(t));
}

bool isSemiPrime(ll n) {
  ll d = any_divisor_of(n);
  return isPrime(d) && isPrime(n / d);
}

bool isSphenicPrime(ll n) {
  ll p = any_divisor_of(n); 
  n /= p;
  if (isPrime(n)) swap(p, n);
  ll q = any_divisor_of(n); 
  n /= q;
  return (p != q) && (q != n) && (n != p) && isPrime(p) && isPrime(q) && isPrime(n);
}

ll d(ll n) {   
  int t = sqrt(sqrt(n)) + 1;
  sieve(t);

  ll res = 1;
  for (int p : prime) {
    if (1LL * p * p * p * p > n) break;
    if (n % p == 0) {
      int f = 0;
      do ++f; while ((n /= p) % p == 0);
      res *= (f + 1);
    }
  }

  if (n == 1) return res;
  if (isPrime(n)) return 2*res;
  if (isSquarePrime(n)) return 3*res;
  if (isSemiPrime(n) || isCubePrime(n)) return 4*res;
  if (isSphenicPrime(n)) return 8*res;
  return res * 6;
}

ll sm(ll n) {
	return n*(n+1)/2;
}

int main() {
	int lim, i=0;
	cin >> lim;
	while (d(sm(i)) <= lim) ++i;
	cout << sm(i) << '\n';
}