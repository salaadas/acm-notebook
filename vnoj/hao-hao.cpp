#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
#define int long long

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define MAX (1e5)

int st[(int)(4*MAX)], A[(int)(MAX)];
int n;
int q;

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = A[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    int p1 = st[p * 2], p2 = st[p * 2 + 1];
    st[p] = p1 > p2 ? p1 : p2;
}

void update(int p, int l, int r, int u, int v) {
    if (u < l || u > r) {
        return;
    }
    if (l == r) {
        st[p] = v;
        return;
     }
    int mid = (l + r) / 2;
    update(p * 2, l, mid, u, v);
    update(p * 2 + 1, mid + 1, r, u, v);
    int p1 = st[p * 2], p2 = st[p * 2 + 1];
    st[p] = p1 > p2 ? p1 : p2;
}

#define infneg -(1e9 + 10)
int get(int p, int l, int r, int u, int v) {
    if (v < l || u > r) {
        return infneg;
    }
    if (u <= l && r <= v) {
        return st[p];
    }
    int mid = (l + r) / 2;
    int p1 = get(p * 2, l, mid, u, v), p2 = get(p * 2 + 1, mid + 1, r, u, v);
    if (p1 == infneg) return p2;
    if (p2 == infneg) return p1;
    return p1 > p2 ? p1 : p2;
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    build(1, 0, n - 1);

    cin >> q;
    while (q--) {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            update(1, 0, n - 1, a - 1, b);
        } else {
            cout << get(1, 0, n - 1, a - 1, b - 1) << endl;
        }
    }

    return 0;
}
