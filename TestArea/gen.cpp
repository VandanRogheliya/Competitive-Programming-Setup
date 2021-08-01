// // generating a random sequence of distinct elements
// #include <bits/stdc++.h>
// using namespace std;

// long long rand(long long a, long long b) {
//     return a + rand() % (b - a + 1);
// }

// int main(int argc, char* argv[]) {
//     srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
//     int n = rand(1, 2);
//     printf("%d\n", n);
//     set<long long> used;
//     for(int i = 0; i < n; ++i) {
//         long long x;
//         do {
//             x = rand(1, 1000);
//         } while(used.count(x));
//         printf("%lld ", x);
//         used.insert(x);
//     }
//     puts("");
// }
// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

long long rand(long long a, long long b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    long long n = rand(1, 5);
    long long q = rand(1, 1);
    // long long q = rand(1, 100);

    printf("%lld %lld 1\n", n, q);

    // set<long long> used;
    for (int i = 0; i < n; ++i) {
        long long x;
    //     do {
            x = rand(1, 5);
    //     } while (used.count(x));
        printf("%lld ", x);
    //     used.insert(x);
    }
    printf("\n");

    for (int i = 0; i < q; i++) {
        long long x;
        x = rand(1, n);
        printf("%lld ", x);

        x = rand(1, n);
        printf("%lld \n", x);

    }
    puts("");
}