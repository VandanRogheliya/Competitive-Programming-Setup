#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("trapv")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef long long int ll;
typedef unsigned long long int ull;
typedef priority_queue<ll> mxhpl;
typedef priority_queue<int> mxhpi;
typedef priority_queue<ll, vector<ll>, greater<ll>> mnhpl;
typedef priority_queue<int, vector<int>, greater<int>> mnhpi;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define REP(i, start, end) for (ll i = start; i <= end; ++i)
#define RREP(i, end, start) for (ll i = end; i >= start; --i)
#define parr(a, n)           \
    rep(i, 0, n) {           \
        cout << a[i] << " "; \
    }                        \
    cout << "\n"
#define sarr(a, n) rep(i, 0, n) cin >> a[i]
#define pb push_back
#define F first
#define S second
#define all(a) a.begin(), a.end()
#define mset(a, x) memset(a, x, sizeof(a))
#define ps(x, y) \
    fixed << setprecision(y) << x  // cout << ps(ans, decimal places);
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

// DEBUGGING
void __print(int x) {
    cerr << x;
}
void __print(long x) {
    cerr << x;
}
void __print(long long x) {
    cerr << x;
}
void __print(unsigned x) {
    cerr << x;
}
void __print(unsigned long x) {
    cerr << x;
}
void __print(unsigned long long x) {
    cerr << x;
}
void __print(float x) {
    cerr << x;
}
void __print(double x) {
    cerr << x;
}
void __print(long double x) {
    cerr << x;
}
void __print(char x) {
    cerr << '\'' << x << '\'';
}
void __print(const char* x) {
    cerr << '\"' << x << '\"';
}
void __print(const string& x) {
    cerr << '\"' << x << '\"';
}
void __print(bool x) {
    cerr << (x ? "true" : "false");
}

template <typename T, typename V>
void __print(const pair<T, V>& x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T& x) {
    int f = 0;
    cerr << '{';
    for (auto& i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() {
    cerr << "]\n";
}
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

// Fast IO
void IO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

#define MOD 1000000007

// CODE
/*******************************************************/
#define MX 100000  // TODO:

const ll mod = MOD;
vector<ll> fact, invf;

ll powmod(ll a, ll b) {
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) res = res * a % mod;
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
    if (n < k) return 0;
    return fact[n] * invf[k] % mod * invf[n - k] % mod;
}

// USAGE:
// build(n); // build first
// nChoosek(n, k); // Use

ll x, y;

void solve() {
    cin >> x >> y;
    if ((x + y) % 3) {
        cout << 0 << endl;
        return;
    }
    build(x+y);
    ll a = 2 * x - y;
    a /= 3;
    ll b = 2 * y - x;
    b /= 3;
    if (a < 0 || b < 0) {
        cout << 0 << endl;
        return;
    }

    cout << nChoosek(a+b, a) << endl;
}

int main() {
    IO();
    int t = 1;

    // cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}

/*******************************************************/
