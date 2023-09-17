#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
// #define int long long
// #define MAX 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int N; cin >> N;
    // find all pairs such that:
    // abcde / fghij = N and uses all number from 0 -> 9
    for (int fghij = 01234; fghij <= 98765 / N; ++fghij) {
        int abcde = fghij * N;
        int checkUsed = (fghij < 10000) ? 0b1 : 0;
        int tmp;
        tmp = abcde; while (tmp) { checkUsed |= 1 << (tmp % 10); tmp /= 10; };
        tmp = fghij; while (tmp) { checkUsed |= 1 << (tmp % 10); tmp /= 10; };
        if (checkUsed == ((1 << 10) - 1)) {
            printf("%d / %d = %d\n", abcde, fghij, N);
        }
    }

    return 0;
}
