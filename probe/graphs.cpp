#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;
using AdjList = vector<vii>;

int main()
{
    AdjList vvii;
    string line;
    while (getline(cin >> ws, line)) {
        stringstream ss(line);
        std::string V;
        ss >> V;
        int v = V[0] - '0';
        int t;
        vvii.push_back(vii());

        while (ss >> t) {
            vvii[v].push_back({t, 1});
        }
    }

    vvii.shrink_to_fit();
    printf("vvii size: %zu\n", vvii.size());

    for (const auto &vl : vvii) {
        for (const auto &pl : vl) {
            cout << pl.first << " ";
        }
        cout << endl;
    }
    return(0);
}
