#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <string>

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

    int m, n;
    vector<int> p(8);
    while (cin >> n >> m) {
        if (!n && !m) break;
        p.clear();
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        p.resize(n);
        while (m--) {
            int cnt = 0;
            int a, b, c; cin >> a >> b >> c;
            do {
                int id1 = find(p.begin(), p.end(), a) - p.begin();
                int id2 = find(p.begin(), p.end(), b) - p.begin();
                if (abs(id2 - id1) >= abs(c)) {
                    for_each(p.begin(), p.end(), [](const auto &d) {cout << d <<  " " << flush;});
                    cout << endl;
                    ++cnt;
                }
            } while (next_permutation(p.begin(), p.end()));
            cout << cnt << endl;
        }
    }

    return 0;
}
