#include <algorithm>
#include <iostream>
#include <utility> // pair
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

constexpr int MAX = 2 * 1e5 + 10;
long dep[MAX];
long cao[MAX];
long bong;

long ft[MAX];

void update(int index, long value) {
    for (; index <= bong; index += index & -index) {
        ft[index] = max(ft[index], value);
    }
}

long query(int index) {
    long res = 0;
    for (; index; index -= index & -index) {
        res = max(res, ft[index]);
    }
    return res;
}

int main()
{
    cin >> bong;
    for (int i = 1; i <= bong; ++i) cin >> cao[i];
    for (int i = 1; i <= bong; ++i) cin >> dep[i];
    for (int i = 1; i <= bong; ++i) {
        update(cao[i], query(cao[i] - 1) + dep[i]);
    }
    cout << query(bong) << endl;

    return(0);
}
