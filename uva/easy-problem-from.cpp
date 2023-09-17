#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <cstdint>

using namespace std;
#define int uint32_t
#define MAX (int)(1e6 + 10)

typedef vector<int> vi;

vi mat[MAX];
int n, q;
int k,v;

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        mat[a].push_back(i + 1);
    }
    for (int i = 0; i < q; ++i) {
        cin >> k >> v;
        --k;
        if (k >= mat[v].size()) {
            cout << 0 << endl;
        } else {
            cout << mat[v][k] << endl;
        }
    }

    return 0;
}
