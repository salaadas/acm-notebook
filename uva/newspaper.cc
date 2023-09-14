#include <iostream>
#include <map>
#include <string>

int main()
{
    int t; std::cin >> t;
    while (t--) {
        int paid; std::cin >> paid;
        long total = 0;
        std::map<char, int> table;
        while (paid--) {
            char c; int v; std::cin >> c >> v;
            table.insert({c, v});
        }
        int lines; std::cin >> lines;
        std::string line;
        while (lines--) {
            std::getline(std::cin >> std::ws, line);
            for (char tc : line) {
                total += table[tc];
            }
        }
        printf("%ld.%2ld$\n", total/100, total%100);
        std::cout << std::flush;
    }
    return(0);
}
