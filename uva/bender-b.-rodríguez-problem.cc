#include <iostream>
#include <string>
#include <vector>

bool changeSign(char cur, char signC, char C)
{
    if (cur == 'x' && signC == '-') return true;
    else if (cur == 'y' && C == 'y' && signC == '+') return true;
    else if (cur == 'z' && C == 'z' && signC == '+') return true;
    return false;
}

int main()
{
    int L;
    while (std::cin >> L) {
        if (L == 0) break;
        char c = 'x';
        int sign = 1;

        while (--L) {
            std::string s; std::cin >> s;
            if (s[0] == 'N') continue;
            if (changeSign(c, s[0], s[1])) sign *= -1;

            if (c == 'x') c = s[1];
            else if (c == 'y' && s[1] == 'y') c = 'x';
            else if (c == 'z' && s[1] == 'z') c = 'x';
        }
        std::cout << (sign == 1 ? "+" : "-") << std::string(1, c) << std::endl;
    }
    return(0);
}
