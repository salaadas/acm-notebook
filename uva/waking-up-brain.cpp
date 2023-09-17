#include <iostream>
#include <vector>
#include <utility> // pair<T, T>
#include <algorithm> // max, min, for_each, ....
#include <sstream>
#include <iterator>
#include <set>
#include <map>

using namespace std;
// #define int long long
// #define MAX

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int parents[27];
int ranks[27];
int n;
int a = 1;
int connections;
map<char, int> nameMap;

int getValOrAdd(char c) {
    if (nameMap.find(c) == nameMap.end()) {
        nameMap[c] = a++;
    }
    return nameMap[c];
}

int findSet(int p) {
    return (p == parents[p]) ? p : findSet(parents[p]);
}

bool isSameSet(int p1, int p2) {
    return findSet(p1) == findSet(p2);
}

void unionSet(int p1, int p2) {
    if (!isSameSet(p1, p2)) {
        if (ranks[p1] > ranks[p2]) {
            parents[p2] = p1;
        } else {
            parents[p1] = p2;
            if (ranks[p1] == ranks[p2]) {
                ++ranks[p2];
            }
        }
    }
}

int numSets() {
    set<int> res;
    for (auto it = nameMap.begin(); it != nameMap.end(); ++it) {
        res.insert(findSet(it->second));
    }
    return res.size();
}

int32_t main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);

    while (cin >> n >> connections) {
        string tmp; cin >> tmp;
        char roots[3];

        for (int i = 0; i < 27; ++i) {
            parents[i] = i;
            ranks[i] = 1;
        }

        for (int i = 0; i < 3; ++i) {
            getValOrAdd(tmp[i]);
            roots[i] = tmp[i];
            // cout << roots[i] << " " << nameMap[roots[i]] << endl;
        }
        unionSet(nameMap[roots[0]], nameMap[roots[1]]);
        unionSet(nameMap[roots[1]], nameMap[roots[2]]);

        vector<string> conn;
        for (int i = 0; i < connections; ++i) {
            cin >> tmp;
            conn.push_back(tmp);
            for (int j = 0; j < 2; ++j) {
                getValOrAdd(tmp[j]);
            }
        }

        int count = 3;
        int years = 0;
        while (count < n) {
            vector<int> awakeCandidates;
            for (auto it = nameMap.begin(); it != nameMap.end(); ++it) {
                int tcount = 0;
                int current = it->second;
                if (isSameSet(current, nameMap[roots[0]])) {
                    continue;
                }
                // cout << "processing: " << current << endl;
                for (string q : conn) {
                    if ((current == nameMap[q[0]] && isSameSet(nameMap[q[1]], nameMap[roots[0]]))
                    || (current == nameMap[q[1]] && isSameSet(nameMap[q[0]], nameMap[roots[0]]))) {
                        ++tcount;
                    }
                }
                if (tcount >= 3) {
                    // cout << "pb: " << current << endl;
                    awakeCandidates.push_back(current);
                }
            }
            if (awakeCandidates.empty()) {
                break;
            }
            for (const auto &i : awakeCandidates) {
                // cout << "i: " << i << endl;
                unionSet(i, nameMap[roots[0]]);
            }
            ++years;
            count += awakeCandidates.size();
        }
        if (count == n) {
            cout << "WAKE UP IN, " << years << ", YEARS" << endl;
        } else {
            cout << "THIS BRAIN NEVER WAKES UP" << endl;
        }

        // for (int i = 1; i <= n; ++i) {
        //     cout << "value: " << i << " set: " << parents[i] << endl;
        // }
    }

    return 0;
}
