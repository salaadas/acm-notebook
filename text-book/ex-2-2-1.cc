#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> arr;
    std::cout << "1. How many ints? ";
    int n; std::cin >> n;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int a; std::cin >> a;
        if (std::find(arr.begin(), arr.end(), a) != arr.end()) {
            ++count;
        }
        arr.push_back(a);
    }

    std::cout << "Dups: " << count << std::endl;
    // std::for_each(arr.begin(), arr.end(), [](const int &i) { std::cout << i << std::endl; });

    std::cout << "2. What the number? ";
    int num; std::cin >> num;

    std::sort(arr.begin(), arr.end(), std::less<int>());
    // std::for_each(arr.begin(), arr.end(), [](const int &i) { std::cout << i << std::endl; });
    auto maxIt = arr.end();
    for (auto s = arr.begin(); s != arr.end(); ++s)
        if (*s > num)
            maxIt = s;

    for (auto i = arr.begin(); i != maxIt; ++i) {
        for (auto j = arr.begin(); j != i; ++j) {
            if (i != j && (*i + *j) == num) {
                std::cout << "=" << *i << "+" << *j << std::endl;
            }
        }
    }

    std::cout << "3. Enter your range? ";
    int b, e; std::cin >> b >> e;
    std::vector<int>::iterator bIt, eIt;
    bIt = std::find_if(arr.begin(), arr.end(), [&b](const int &i) { return i >= b; });
    for (auto s = arr.begin(); s != arr.end(); ++s) {
        if (*s <= e ) {
            eIt = s;
        }
    }

    if (*eIt < *bIt) {
        std::cout << "Oh no, the range is messed up (start: " << *bIt << ", end: " << *eIt << ")" << std::endl;
        return 0;
    }

    std::cout << "> ";
    for (auto s = bIt; s <= eIt; ++s) {
        std::cout << *s;
        if (s != eIt) std::cout << " ";
        else std::cout << std::endl;
    }



    return 0;
}
