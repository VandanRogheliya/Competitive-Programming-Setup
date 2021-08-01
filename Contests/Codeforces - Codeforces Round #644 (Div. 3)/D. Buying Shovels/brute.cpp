#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {

        long long n, k;
        cin >> n >> k;

        for (long long i = k; i >= 1;i--) {
            if (n % i == 0) {
                cout << n / i << "\n";
                continue;
            }
        }

    }
    return 0;
}