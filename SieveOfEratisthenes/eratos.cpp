#include <vector>
#define N 10000

void eratos() {
    int a[N];
    vector<int> primes(N);
    for (int i = 2; i < N; ++i) a[i] = i;
    for (int i = 2; i < N; ++i) {
        if (a[i]) {
            for (int j = i; i * j < N; ++j) a[i * j] = 0;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (a[i]) primes.push_back(a[i]);
    }
}

