#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// O(nlogn)
ll lis(vector<ll> const& a) {
  ll n = a.size();
  const ll INF = 1e9;
  vector<ll> d(n + 1, INF);
  d[0] = -INF;

  for (ll i = 0; i < n; i++) {
    ll j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (d[j - 1] < a[i] && a[i] < d[j])
      d[j] = a[i];
  }

  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    if (d[i] < INF)
      ans = i;
  }
  return ans;
}

int main() {
  vector<ll> a = { 4,3,2,5, 9, 10, 100 };
  cout << lis(a);
  return 0;
}