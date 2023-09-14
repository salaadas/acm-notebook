#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int board[22][22];

int n, m;
int g(int i) {
    return i ^ (i >> 1);
}

int main()
{
    cin >> n >> m;
    int cnt = 0;
    bool sw = false;
    for (int i = 0, j = 1; i < (1 << m); ++i, sw = !sw) {
        j = sw ? (1 << n) : 1;
        for (; j < (1 << n) + 1 && j > 0; sw ? --j : ++j) {
            board[j - 1][i] = g(cnt++);
        }
    }

    for (auto i = begin(board); i != end(board) && i != begin(board) + (1 << n); ++i) {
        for (auto j = begin(*i); j != end(*i) && j != begin(*i) + (1 << m); ++j) {
            cout << *j << " ";
        }
        cout << endl;
    }

    return 0;
}
