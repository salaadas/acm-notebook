#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>

bool permutation(const std::string &s1, const std::string &s2)
{
    if (s1.length() != s2.length()) {
        return false;
    }
    int count[UCHAR_MAX + 1] = {};
    for (unsigned char c : s1) ++count[c];
    for (unsigned char c : s2) --count[c];
    for (int x : count) {
        if (x) {
            return false;
        }
    }
    return true;
}

int main()
{
    constexpr int GRID_SZ = 9;
    char grid[GRID_SZ][GRID_SZ] = {
        {'O', 'B', 'I', 'D', 'A', 'I', 'B', 'K', 'R'},
        {'R', 'K', 'A', 'U', 'L', 'H', 'I', 'S', 'P'},
        {'S', 'A', 'D', 'I', 'Y', 'A', 'N', 'N', 'O'},
        {'H', 'E', 'I', 'S', 'A', 'W', 'H', 'I', 'A'},
        {'I', 'R', 'A', 'K', 'I', 'B', 'U', 'L', 'S'},
        {'M', 'F', 'B', 'I', 'N', 'T', 'R', 'N', 'O'},
        {'U', 'T', 'O', 'Y', 'Z', 'I', 'F', 'A', 'H'},
        {'L', 'E', 'B', 'S', 'Y', 'N', 'U', 'N', 'E'},
        {'E', 'M', 'O', 'T', 'I', 'O', 'N', 'A', 'L'}
    };

    std::vector<std::string> names = {
        "RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"
    };
    std::vector<int> occurence(names.size(), 0);

    for (int y = 0; y < GRID_SZ; ++y) {
        for (int x = 0; x < GRID_SZ; ++x) {
            for (int nIdx = 0; nIdx < static_cast<int>(names.size()); ++nIdx) {
                std::string n = names[nIdx];
                // std::cout << "n: " << n << std::endl;
                std::string s;
                if (x + n.length() - 1 < GRID_SZ) {
                    for (int i = 0; i < static_cast<int>(n.length()); ++i)
                        s += grid[y][x + i];
                    if (permutation(s, n))
                        ++occurence[nIdx];
                }
                // std::cout << "1s: " << s << std::endl;
                s = "";
                if (x - n.length() + 1 >= 0) {
                    for (int i = 0; i < n.length(); ++i)
                        s += grid[y][x - i];
                    if (permutation(s, n))
                        ++occurence[nIdx];
                }
                s = "";
                if (y + n.length() - 1 < GRID_SZ) {
                    for (int i = 0; i < n.length(); ++i)
                        s += grid[y + i][x];
                    if (permutation(s, n))
                        ++occurence[nIdx];
                }
                s = "";
                if (y - n.length() + 1 >= 0) {
                    for (int i = 0; i < n.length(); ++i)
                        s += grid[y - i][x];
                    if (permutation(s, n))
                        ++occurence[nIdx];
                }
            }
        }
    }
    int max = -1;
    int idx = -1;
    for (int i = 0; i < occurence.size(); ++i) {
        if (occurence[i] > max) {
            max = occurence[i];
            idx = i;
        }
    }
    std::cout << names[idx] << std::endl;

    return 0;
}
