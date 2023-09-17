#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <sstream>

using namespace std;
// #define int long long
// #define MAX

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t;
int comps;
vi P;
vi Rank;
int suc = 0 , unsuc = 0;

int findSet(int p) {
    if (p == P[p]) {
        return p;
    } else {
        return findSet(P[p]);
    }
}

bool isSameSet(int p1, int p2) {
    return findSet(p1) == findSet(p2);
}

void unionSet(int p1, int p2) {
    if (!isSameSet(p1, p2)) {
        int pr1 = findSet(p1), pr2 = findSet(p2);
        if (Rank[pr1] > Rank[pr2]) {
            P[pr2] = pr1;
        } else {
            P[pr1] = pr2;
            if (Rank[pr1] == Rank[pr2]) {
                ++Rank[pr2];
            }
        }
    }
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    cin >> t;
    cin >> comps;
    while (t--) {
        P.clear(); P.assign(comps + 1, 0);
        Rank.clear(); Rank.assign(comps + 1, 0);
        suc = 0, unsuc = 0;
        for (int i = 1; i <= comps; ++i) {
            P[i] = i;
        }
        string line;
        while (true && !cin.eof()) {
            getline(cin >> ws, line);
            stringstream ss(line);
            if (line.length() == 1) {
                ss >> comps;
                goto printout;
            }
            char c;
            int l, r;
            ss >> c >> l >> r;
            switch (c) {
                case 'c':
                unionSet(l, r);
                break;
                case 'q':
                if (isSameSet(l, r))
                ++suc;
                else
                ++unsuc;
                break;
            }
        }
printout:
        cout << suc << ", " << unsuc << endl;
        if (t != 0) {
            cout << endl;
        }
    }

    return 0;
}
