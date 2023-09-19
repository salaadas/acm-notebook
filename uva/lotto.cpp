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

    int k;
    bool first = true;
    while (cin >> k) {
        if (k == 0) break;
        if (!first) cout << endl;
        else first = false;
        int S[14];
        for (int i = 0; i < k; ++i) cin >> S[i];
        for (int a = 0; a < k - 5; ++a)
            for (int b = a + 1; b < k - 4; ++b)
                for (int c = b + 1; c < k - 3; ++c)
                    for (int d = c + 1; d < k - 2; ++d)
                        for (int e = d + 1; e < k - 1; ++e)
                            for (int f = e + 1; f < k; ++f)
                                cout << S[a] << " " << S[b] << " "
                                << S[c] << " " << S[d] << " " << S[e] << " " << S[f] << endl;
    }

    return 0;
}
