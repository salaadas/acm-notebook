#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdint>

#define int uint16_t

int N, T, P;

using Stat = std::pair<std::pair<int, int>, int>; // <<id, score>, total_solved>

int32_t main()
{
    std::cin >> N >> T >> P;
    std::vector<int> score(T, N);
    int solved[2010][2010] = {};
    std::vector<Stat> c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < T; ++j) {
            int a; std::cin >> a;
            score[j] -= a;
            solved[i][j] = a;
        }
    }
    for (int i = 0; i < N; ++i) {
        int s = 0;
        int t = 0;
        for (int j = 0; j < T; ++j) {
            if (solved[i][j]) {
                s += score[j];
                ++t;
            }
        }
        c.push_back({{i + 1, s}, t});
    }

    std::sort(c.begin(), c.end(), [](Stat s1, Stat s2) {
        int v1 = s1.first.second, v2 = s2.first.second;
        if (v1 > v2) {
            return true;
        } else if (v1 == v2) {
            if (s1.second > s2.second) return true;
            else if (s1.second == s2.second) {
                // std::cout << "reched" << std::endl;
                if (s1.first.first < s2.first.first) return true;
                else return false;
            }
        } else {
            return false;
        }
    });

    for (int i = 0; i < N; ++i) {
        if (c[i].first.first == P) {
            std::cout << c[i].first.second << " " << i + 1 << std::endl;
        }
    }
    return(0);
}
