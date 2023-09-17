#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <cstdint>

using namespace std;
#define int long long
#define inf (1e9 + 100)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int segtree[(int)(4*1e5+10)], a[(int)(1e5 + 10)];

int m, q;

inline
int left(int i) {
    return i << 1;
}

inline
int right(int i) {
    return (i << 1) + 1;
}

void build(int p, int l, int r) {
    if (l == r) {
        // cout << "assigning " << a[l] << " to " << p << endl;
        segtree[p] = a[l];
    }
    else {
        int mid = (l+r)/2;
        build(left(p), l, mid);
        build(right(p), mid + 1, r);

        int p1 = segtree[left(p)],
        p2 = segtree[right(p)];

        segtree[p] = p1 <= p2 ? p1 : p2;
    }
}

void update(int p, int l, int r, int i, int v) {
    if (i < l || i > r) {
        return;
    }
    if (l == r) {
        segtree[p] = v;
        return;
    }
    int mid = (l+r) / 2;
    update(left(p), l, mid, i, v);
    update(right(p), mid+1, r, i, v);
    int p1 = segtree[left(p)], p2 = segtree[right(p)];
    segtree[p] = p1 < p2 ? p1 : p2;
}

int get(int p, int l, int r, int u, int v, int k) {
    // cout << "the p is " << p << endl;
    // cout << "u " << u << "; v " << v << endl;
    // cout << "r " << r << "; l " << l << endl;
    if (v < l || u > r) {
        return inf;
    }
    // doan [l, r] nam hoan toan trong doan [u, v]
    if (u <= l && r <= v) {
        // cout << "segtree[p] " << segtree[p] << endl;
        return segtree[p] >= k ? segtree[p] : inf;
    }
    int mid = (l + r) / 2;
    int p1 = get(left(p), l, mid, u, v, k);
    int p2 = get(right(p), mid + 1, r, u, v, k);
    int res = p1 < p2 ? p1 : p2;

    return res >= k ? res : inf;
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin >> m >> q;

    // segtree.assign(4*m, 0);

    for (int i = 0; i < m; ++i) {
        int ta; cin >> ta;
        a[i] = ta;
    }

    build(1, 0, m - 1);

    while (q--) {
        int cmd, u, v, l, r;
        cin >> cmd;
        if (cmd == 1) {
            cin >> u >> v;
            update(1, 0, m - 1, u - 1, v);
        } else {
            cin >> l >> r >> u;
            int q = get(1, 0, m - 1, l, r, u);
            cout << (q == (1e9 + 100) ? -1 : q) << endl;
        }
    }

    return 0;
}
