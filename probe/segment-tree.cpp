#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef std::vector<int> vi;
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;

// help solve dynamic range queries

// example: RMQ (Range Minimum Query) problem

// value: 18 17 13 19 15 11 20
// index:  0  1  2  3  4  5  6

class SegmentTree {
    private:
    vi st, A;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) {
        if (L == R) st[p] = L;
        else {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int tL, int tR) {
        if (tL > R || tR < L) return -1;
        if (L >= tL && R <= tR) return st[p];
        int p1 = rmq(left(p), L, (L+R)/2, tL, tR),
        p2 = rmq(right(p), (L+R)/2+1, R, tL, tR);
        if (p1 == -1) return p2;
        if (p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void update(int p, int L, int R, int idx, int nval) { // p giong nhu con tro
        if (L == R) {
            st[p] = nval;
        } else {
            int mid = (L+R)/2;
            if (idx <= mid) {
                update(left(p), L, mid, idx, nval);
            } else {
                update(right(p), mid + 1, R, idx, nval);
            }
            st[p] = A[left(p)] <= A[right(p)] ? left(p) : right(p);
        }
    }
    public:
    SegmentTree(const vi &_A)
    {
        A = _A;
        n = (int)A.size();
        st.assign(4*n, 0); // will not exceed 4n
        build(1, 0, n - 1);
    }

    int rmq(int i, int j) {
        return rmq(1, 0, n - 1, i, j);
    }
};

class SumSegmentTree {
    private:
    vi st, A;
    int n;

    inline int left(int p) { return p << 1; }
    inline int right(int p) { return (p << 1) + 1; }
    void build(int p, int L, int R) {
        if (L == R) st[p] = A[L]; // store itself's index if bounds are the same
        else {
            build(left(p), L, (R+L)/2);
            build(right(p), (R+L)/2+1, R);
            st[p] = st[left(p)] + st[right(p)];
        }
    }
    int sum(int p, int L, int R, int tL, int tR) {
        if (tL > R || tR < L) return 0;
        if (L >= tL && R <= tR) return st[p];
        int res = sum(left(p), L, (L+R)/2, tL, tR) + sum(right(p), (L+R)/2+1, R, tL, tR);
        return res;
    }
    public:
    SumSegmentTree(vi _A) {
        A = (_A);
        n = (int)A.size();
        st.assign(4*n, 0);
        build(1, 0, n - 1);
    }

    int sum(int l, int r) {
        return sum(1, 0, n - 1, l, r);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vi A = {18, 17, 13, 19, 15, 11, 20};
    SegmentTree st1(A);
    printf("min element from 0 -> n - 1: %d\n", st1.rmq(0, A.size() - 1));
    printf("min element from 1 -> 2    : %d\n", st1.rmq(1, 2));
    printf("min element from 3 -> 5    : %d\n", st1.rmq(3, 5));
    printf("min element from 3 -> 3    : %d\n", st1.rmq(3, 3));

    SumSegmentTree st2(A);
    printf("sum of 0 -> n: %d\n", st2.sum(0, A.size() - 1));
    printf("sum of 0 -> 5: %d\n", st2.sum(0, 5));
    printf("sum of 3 -> 3: %d\n", st2.sum(3, 3));

    return(0);
}
