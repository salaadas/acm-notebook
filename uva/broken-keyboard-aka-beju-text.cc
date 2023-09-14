#include <iostream>
#include <string>

int main()
{
    std::string line;
    while (std::getline(std::cin >> std::ws, line)) {
        std::string result;
        result.reserve(1048576);
        std::string::iterator cursor = result.begin();
        for (char c : line) {
            if (c == '[') {
                cursor = result.begin();
            } else if (c == ']') {
                cursor = result.begin() + result.length();
            } else {
                result.insert(cursor, c);
                cursor++;
            }
        }
        std::cout << result << std::endl;
    }
    return(0);
}
