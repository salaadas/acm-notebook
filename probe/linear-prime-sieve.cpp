#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

// idea:
// for every number from 2 to N
//  check if that number if prime,
//  if it is, then store it in
//  the prime list
// afterwards,
//  for every prime number j <= to the smallest
//  prime factor p of i:
//   mark all numbers i*p as non_prime
//   mark the smallest prime factor of i*p as j

int main()
{
    constexpr int N = 100;
    vi spf(N + 1, 0); // smallest prime factor
    vi pr; // list of primes
    for (int i = 2; i <= N; ++i) {
        // if there is no smallest prime factor -> that num is prime
        if (!spf[i]) {
            pr.push_back(i);
            spf[i] = i; // the smallest prime factor is itself
        }
        for (int j = 0; j < (int)pr.size() &&
                 i * pr[j] <= N &&
                 pr[j] <= spf[i]; ++j) {
            spf[i * pr[j]] = pr[j];
        }
    }

    // logging the output
    printf("primes:\n");
    for (const auto &i : pr) {
        printf("%d ", i);
    }
    printf("\n");

    // printf("factors:\n");
    // for (const auto &i : spf) {
    //     printf("%d ", i);
    // }
    // printf("\n");
    return(0);
}
