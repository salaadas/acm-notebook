#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <sstream>

using namespace std;
// #define int long long
#define MAX (int)(2e5 + 10)

typedef vector<int> vi;

vi bit(MAX);
vi A(MAX);
int n;

int getMinBit(int i) {
    return i & ~(i - 1);
}

// range sum query
int rsq(int r) {
    int sum = 0;
    for (; r > 0; r -= getMinBit(r)) {
        sum += bit[r];
    }
    return sum;
}

int rsq(int l, int r) {
    return rsq(r) - rsq(l - 1);
}

void adjust(int index, int value) {
    for (; index <= (int)n; index += getMinBit(index)) {
        bit[index] += value;
    }
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    int cases = 0;
    bool first = true;
    while (cin >> n) {
        if (n == 0) break;

        fill(bit.begin(), bit.end(), 0);
        fill(A.begin(), A.end(), 0);

        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            adjust(i + 1, A[i]);
        }

        if (!first) printf("\n");
        else first = false;
        printf("Cases %d:\n", ++cases);

        string line;
        while (getline(cin >> ws, line)) {
            if (line == "END") break;
            stringstream ss(line);
            char cmd;
            int l, r;
            ss >> cmd >> l >> r;
            if (cmd == 'M') {
                int res = rsq(l, r);
                cout << res << endl;
            } else {
                // Thank you my man
                // https://github.com/morris821028/UVa/blob/master/volume120/12086%20-%20Potentiometers%5BBIT%5D.cpp#L3
                // This is truly a work of art
                adjust(l, r - A[l-1]);
                A[l-1] = r;
            }
        }
    }

    return 0;
}
