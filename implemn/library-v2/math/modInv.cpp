//used in solving linear congruences a*x = b (mod n)
// getInv finds a^-1 mod n
// x = a^-1 * b % n
//TODO:CONDITION: gcd(a, n) = 1
ll extended_euclidean(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll x1, y1;
  ll d = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}
ll getInv(ll a, ll n) { // O(log(max(a,n))) 
  ll x, y;
  ll g = extended_euclidean(a, n, x, y);
  
  if (g != 1) {
    // TODO: -1 means not possible
    return -1;
  }
  
  x = (x % n + n) % n;
  return x;

}