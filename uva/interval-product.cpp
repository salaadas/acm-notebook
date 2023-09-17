#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....

using namespace std;
// #define int long long
#define MAX (int)(1e5 + 10)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi A(MAX);
vi st(4*MAX);
vi stMult(4*MAX);
int n, k;

inline
int left(int p)
{
    return (p << 1);
}

inline
int right(int p)
{
    return (p << 1) + 1;
}

void build(int p, int l, int r)
{
    if (l == r) {
        st[p] = stMult[p]= A[l];
    }
    else {
        int mid = (l+r)/2;
        build(left(p), l, mid);
        build(right(p), mid+1, r);
        st[p] = st[left(p)] <= st[right(p)] ? st[left(p)] : st[right(p)];
        stMult[p] = stMult[left(p)] * stMult[right(p)];
    }
}

void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        st[p] = val;
        stMult[p] = val;
    } else {
        int mid = (l+r)/2;
        if (idx <= mid) {
            update(left(p), l, mid, idx, val);
        } else {
            update(right(p), mid+1, r, idx, val);
        }
        st[p] = st[left(p)] <= st[right(p)] ? st[left(p)] : st[right(p)];
        stMult[p] = stMult[left(p)] * stMult[right(p)];
    }
}

int multQuery(int p, int l, int r, int u, int v) {
    if (r < u || l > v || l > r) {
        return 1;
    }
    if (u <= l && r <= v) {
        return stMult[p];
        // return st[p];
    }
    int mid = (l+r)/2;
    return multQuery(left(p), l, mid, u, v) * multQuery(right(p), mid+1, r, u, v);
    // int p1 = multQuery(left(p), l, mid, u, v);
    // int p2 = multQuery(right(p), mid+1, r, u, v);
    // return p1 <= p2 ? p1 : p2;
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    while (cin >> n >> k) {
        A.clear();
        st.clear();
        stMult.assign(4*MAX, 1);
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        build(1, 0, n - 1);
        while (k--) {
            char cmd;
            int l, r;
            cin >> cmd >> l >> r;
            if (cmd == 'C') {
                --l; // change index;
                update(1, 0, n - 1, l, r);
            } else {
                --l; --r;
                int res = multQuery(1, 0, n - 1, l, r);
                cout << (res > 0 ? '+' : res == 0 ? '0' : '-');
            }
        }
        cout << endl;
    }

    return 0;
}
