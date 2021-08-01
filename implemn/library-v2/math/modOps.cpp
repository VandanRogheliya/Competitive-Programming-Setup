// Adding
ll ans = ((ll)a+b) % mod;

// Multiply
ll ans = ((ll)a*b) % mod;

// Sub
ll ans = ((a-b)%mod + mod) % mod;

// div
ll mpow(ll a, ll b) {
  ll res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}

ll divMod(ll a, ll b) {
  return a * mpow(b, mod-2) % mod;
}