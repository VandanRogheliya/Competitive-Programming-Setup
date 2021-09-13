#include<bits/stdc++.h>
using namespace std;

// DEBUGGING
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char* x) { cerr << '\"' << x << '\"'; }
void __print(const string& x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const pair<T, V>& x) { cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template<typename T>
void __print(const T& x) { int f = 0; cerr << '{'; for (auto& i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}"; }
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// Fast IO
void IO() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
}

//CODE
/*******************************************************/
#define MX 50
#define MAX_CHAR 28
const int CHAR_OFFSET = 'a' - 2;
/*

Input:
1. Plain text: string of lowercase letters -> abc

  :
1. Cipher text: array of numbers -> 43,23,12
2. Public key: (e,n)
3. Private key: (d,n)
4. Decrypt the cipher text

*/

class RSAAlgo {
  // List of primes
  vector<long long> primes;

  void generatePrimes() {
    vector<long long> sieve(MX);
    sieve[0] = 1;
    for (int currentNum = 2; currentNum * currentNum < MX; currentNum++) {
      if (sieve[currentNum]) continue;
      primes.push_back(currentNum);
      for (int multiple = currentNum; multiple < MX; multiple += currentNum) {
        sieve[currentNum] = 1;
      }
    }
  }

  // Returns random number between a and b inclusive
  long long randBetween(long long a, long long b) {
    return a + rand() % (b - a + 1);
  }

  long long phi(long long p, long long q) {
    return (p - 1) * (q - 1);
  }

  // finds d in (d * a) % m = 1
  long long modInverse(long long a, long long m) {
    for (int x = 1; x < m; x++)
      if (((a % m) * (x % m)) % m == 1)
        return x;
    return -1;
  }

  long long mpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    for (; b; b >>= 1) {
      if (b & 1)
        res = res * a % mod;
      a = a * a % mod;
    }
    return res;
  }

  void generateKeys(long long seed) {
    generatePrimes();
    srand(seed);
    long long p, q;
    do {

      p = primes[randBetween(0, primes.size() - 1)];
      q = primes[randBetween(0, primes.size() - 1)];
      // ensures p and q are unique
      while (p == q) {
        q = primes[randBetween(0, primes.size() - 1)];
      }
    } while (p * q <= MAX_CHAR);
    long long n = p * q;
    long long phiOfN = phi(p, q);
    long long e = -1;
    long long d = -1;
    for (int index = 2; index < phiOfN; index++) {
      if (n % index == 0) continue;
      e = index;
      d = modInverse(e, phiOfN);
      if (d != -1) break;
    }

    assert(e != -1);
    assert(d != -1);

    publicKey = { e, n };
    privateKey = { d, n };
  }

  void encryptText() {
    for (char c : plainText) {
      c = c - CHAR_OFFSET;
      cipherText.push_back(mpow((long long)c, publicKey.first, publicKey.second));
    }
  }

public:
  string plainText;
  vector<long long> cipherText;
  pair<long long, long long> publicKey;
  pair<long long, long long> privateKey;

  RSAAlgo(string plainText, long long seed) {
    this->plainText = plainText;
    generateKeys(seed);
    encryptText();
  }

  string getDecipherText() {
    string decipherText = "";
    for (long long encryptedChar : cipherText) {
      long long decipheredChar = mpow(encryptedChar, privateKey.first, privateKey.second);
      decipherText.push_back(decipheredChar + CHAR_OFFSET);
    }
    return decipherText;
  }
};

int main() {
  // Handling file input
  IO();

  string plainText; cin >> plainText;
  RSAAlgo test = RSAAlgo(plainText, 2);

  cout << "Public key: " << test.publicKey.first << ", " << test.publicKey.second << "\n";
  cout << "Private key: " << test.privateKey.first << ", " << test.privateKey.second << "\n";
  cout << "Cipher text array: ";
  for (auto encyptedChar : test.cipherText) {
    cout << encyptedChar << ", ";
  }
  cout << "\n";

  cout << "Deciphered text: " << test.getDecipherText() << "\n";
  cout << "Plain text given: " << test.plainText << "\n";
  return 0;
}

/*******************************************************/
