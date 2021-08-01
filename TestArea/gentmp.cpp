// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

long long rand(long long a, long long b) {
  return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  int n = rand(2, 10);
  printf("%d\n", n);
  set<long long> used;
  for (int i = 0; i < n; ++i) {
    long long x;
    do {
      x = rand(1, 1000000000000000000);
    } while (used.count(x));
    printf("%lld ", x);
    used.insert(x);
  }
  puts("");
}