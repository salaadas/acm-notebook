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

    string a, b; cin >> a >> b;
    const int m = (int)a.length(), n = (int)b.length();
    vector<vector<int>> lcs(m + 1);
    for (int i = 0; i <= m; ++i) {
        lcs[i].assign(n + 1, 0);
    }
    int result = 0;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (!i || !j) {
                lcs[i][j] = 0;
            } else if (a[i-1] == b[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                result = max(lcs[i][j], result);
            } else {
                lcs[i][j] = 0;
            }
        }
    }
    printf("Longest common substring length is: %d\n", result);

    return 0;
}
