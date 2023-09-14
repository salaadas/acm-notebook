#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
// #define int long long

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi ft, a;

int m, q;

// change position at index to value
void adjust(int index, int value) {
}

int qu(int p, int tl, int tr, int l, int r, int k) {
}

int query(int l, int r, int k) {
    qu(1, 0, m - 1, l, r, k);
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin >> m >> q;
    ft.assign(4*m + 1, 0);
    while (m--) {
        int ta; cin >> ta;
        a.push_back(a);
    }
    while (q--) {
        int cmd, u, v, l, r;
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d%d", &u, &v);
            adjust(u, v);
        } else {
            scanf("%d%d%d", &l, &r, &u);
            printf("%d\n", query(l, r, u));
        }
    }

    return 0;
}
