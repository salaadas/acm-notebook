// https://stackoverflow.com/questions/12884486/why-gray-code-is-an-exclusive-or-of-the-bits-in-a-binary-code
#include <iostream>
int g(int n)
{
    return n ^ (n >> 1);
}

int reverse_g(int g)
{
    int n = 0;
    for (; g; g >>= 1) {
        n ^= g;
    }
    return n;
}

int main()
{
    for (int i = 0; i < 15; ++i) {
        std::cout << g(i) << std::endl;
    }
    return(0);
}
