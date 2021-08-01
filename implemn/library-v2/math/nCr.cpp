const ll mod = 998244353;
vector<ll> fact, invf;

ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

void build(int n) {
  fact = vector<ll>(n + 1, 1);
  invf = vector<ll>(n + 1, 1);
  for (int i = 2; i <= n; i++)
    fact[i] = fact[i - 1] * i % mod;
  invf[n] = powmod(fact[n], mod - 2);
  for (int i = n - 1; i >= 2; i--)
    invf[i] = invf[i + 1] * (i + 1) % mod;
}

ll nChoosek(int n, int k) {
  if (n < k)
    return 0;
  return fact[n] * invf[k] % mod * invf[n - k] % mod;
}


// USAGE:
// build(n); // build first
// nChoosek(n, k); // Use