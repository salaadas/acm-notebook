#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <iterator>

using namespace std;
#define int long long
#define MOD (int)(1e9 + 7)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

constexpr int N = (1e5 + 10);
int n, q;
int A[N];
int st[N*4];
vi lazyAdd(N*4, 0);
vi lazyMult(N*4, 1);

void build(int p, int l, int r) {
    if (l == r) {
        st[p] = A[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
}

void pushMult(int p) {
    lazyMult[2*p]  *= lazyMult[p];
    st[2*p] *= lazyMult[p];

    lazyMult[2*p+1]  *= lazyMult[p];
    st[2*p+1] *= lazyMult[p];

    lazyMult[p] = 1;
}

void pushAdd(int p) {
    lazyAdd[2*p] += lazyAdd[p];
    st[2*p] += lazyAdd[p];

    lazyAdd[2*p+1] += lazyAdd[p];
    st[2*p+1] += lazyAdd[p];

    lazyAdd[p] = 0;
}

void multRange(int p, int l, int r, int u, int v, int k) {
    if (r < u || l > v) {
        return;
    }
    if (l == r) {
        st[p] *= k;
        lazyAdd[p] *= k;
        return;
    }
    pushMult(p);
    pushAdd(p);
    int mid = (l+r)/2;
    multRange(2*p, l, mid, u, v, k);
    multRange(2*p+1, mid+1, r, u, v, k);
}

void addRange(int p, int l, int r, int u, int v, int k) {
    if (r < u || l > v) {
        return;
    }
    if (l == r) {
        st[p] += k;
        lazyAdd[p] += k;
        return;
    }
    pushMult(p);
    pushAdd(p);
    int mid = (l+r)/2;
    addRange(2*p, l, mid, u, v, k);
    addRange(2*p+1, mid+1, r, u, v, k);
}

void updateRange(int p, int l, int r, int u, int v, int k) {
    if (r < u || l > v) {
        return;
    }
    if (l == r) {
        st[p] = k;
        return;
    }
    int mid = (l+r)/2;
    updateRange(2*p, l, mid, u, v, k);
    updateRange(2*p+1, mid+1, r, u, v, k);
}

int get(int p, int l, int r, int pos) {
    if (l == r) {
        return st[p];
    }
    pushAdd(p);
    pushMult(p);
    int mid = (l+r)/2;
    if (pos <= mid) {
        return get(2*p, l, mid, pos);
    } else {
        return get(2*p+1, mid+1, r, pos);
    }
}

int sumRange(int p, int l, int r, int u, int v) {
    if (r < u || l > v) {
        return 0;
    } else if (l == r) {
        return st[p];
    }
    pushAdd(p);
    pushMult(p);
    int mid = (l+r)/2;
    return (sumRange(p*2, l, mid, u, v) + sumRange(p*2+1, mid+1, r, u, v)) % (MOD);
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    build(1, 0, n - 1);

    while (q--) {
        // cout << "--------------------" << endl;
        // for (int i = 0; i < n; ++i) {
        //     cout << get(1, 0, n - 1, i) << endl;
        // }

        int cmd, l, r, x;
        cin >> cmd >> l >> r;
        --l;
        --r;
        if (cmd == 1) {
            cin >> x;
            addRange(1, 0, n - 1, l, r, x);
        } else if (cmd == 2) {
            cin >> x;
            multRange(1, 0, n - 1, l, r, x);
        } else if (cmd == 3) {
            cin >> x;
            updateRange(1, 0, n - 1, l, r, x);
        } else {
            cout << sumRange(1, 0, n - 1, l, r) << endl;
        }
    }

    return 0;
}
