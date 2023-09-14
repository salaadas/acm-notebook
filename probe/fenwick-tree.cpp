// BIT - binary indexed tree

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

inline int LSOne(int i)
{
    return (i & (-i));
}

class FenwickTree {
    private:
    vi ft;
    int g(int i) {
        return LSOne(i);
    }
    public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0); // 1-based
    }
    int rsq(int b) { // return rsq(1, b)
        int sum = 0;
        for (; b; b -= g(b)) {
            sum += ft[b];
        }
        return sum;
    }

    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
    }

    int sum(int r) {
        int res = 0;
        for (; r > 0; r = g2(r)) {
            res += ft[r];
        }
        return res;
    }

    int sum(int r, int q) {
        return sum(q) - (r == 1 ? 0 : sum(q - 1));
    }

    void increase(int i, int delta) {
        for (int j = 1; g2(j) < i && i < j; ++j) {
            ft[j] += delta;
        }
    }

    void adjust(int k, int v) {
        for (; k < (int)ft.size(); k += g(k)) {
            ft[k] += v;
        }
    }
};

int main()
{
    int f[] = { 2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9 }; // m = 11 scores
    FenwickTree ft(10); // declare fenwicktree for range [1 ... 10]
    // insert these manually
    for (int i = 0; i < 11; ++i) ft.adjust(f[i], 1);
    printf("%d\n", ft.rsq(3, 6));
    printf("%d\n", ft.sum(3, 6));


    return(0);
}

// another implementation of fenwick tree -- also called binary indexed tree (bit)
// https://vnoi.info/wiki/algo/data-structures/fenwick.md

#define N (2 * 1e5 + 10)
int bit[N];
int num;

// find sum
inline
int getSmallestSetBit(int n) {
    return n & (-n);
}

// get sum of of array from index [1 -> n]
int getSum(int idx) {
    int res = 0;
    for (; idx; idx -= idx & ~(idx - 1)) {
        res += bit[idx];
    }
    return res;
}

void update(int idx, int value) {
    for (; idx <= num; idx += idx & ~(idx - 1)) {
        bit[idx] += value;
    }
}
