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

    int a, b, c;
    cin >> a >> b >> c;
    bool solved = false;
    for (int i = -22; i <= 22 && !solved; ++i) if (i*i <= c)
        for (int j = -100; j <= 100 && !solved; ++j) if (i!=j && i*i + j*j <= c)
            for (int k = -100; k <= 100 && !solved; ++k)
                if ((i - k) && (j - k)
                && i+j+k == a && i*j*k == b && i*i+j*j+k*k == c) {
                    printf("%d %d %d\n", i, j, k);
                    solved = true;
                }
    printf("No solution\n");

    return 0;
}
