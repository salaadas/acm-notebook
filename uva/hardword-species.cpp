#include <iostream>
#include <map>
#include <string>

int main()
{
    int t; std::cin >> t;
    while (t--) {
        std::map<std::string, int> m;
        std::string line; int count = 0;
        getline(std::cin >> std::ws, line); // blank line
        while (getline(std::cin >> std::ws, line)) {
            ++count;
            if (m.find(line) != m.end())
            m[line] += 1;
            else
            m.insert({line, 1});
        }
        ++count;
        for (const auto &[key, value] : m) {
            printf("%s %.4f\n", key.c_str(), 100 * static_cast<double>(value) / count);
        }
    }
    return(0);
}
