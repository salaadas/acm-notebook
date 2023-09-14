// https://the-art-of-programming-by-july.readthedocs.io/en/latest/ebook/en/35.0/
#include <iostream>

// indexed from 1
// USING DIVIDE AND CONQUER
void myShuffle(int *a, int n)
{
    int temp, i;
    if (n == 1) {
        temp = a[1];
        a[1] = a[2];
        a[2] = temp;
        return;
    }

    int n2 = n*2, n3 = n/2;
    if (n % 2 == 1) {
        temp = a[n];
        for (i = n + 1; i <= n2; ++i) {
            a[i - 1] = a[i];
        }
        a[n2] = temp;
        --n;
    }

    for (i = n3 + 1; i <= n; ++i) {
        temp = a[i];
        a[i] = a[i + n3];
        a[i + n3] = temp;
    }

    myShuffle(a, n3);
    myShuffle(a + n, n3);
}

int main()
{
    constexpr int DECK_SZ = 52;
    constexpr int HALF_DECK_SZ = DECK_SZ / 2;
    int deck[52 + 10];

    for (int i = 1; i <= DECK_SZ; ++i) {
        deck[i] = i;
    }

    myShuffle(deck, HALF_DECK_SZ);

    for (int i = 1; i <= DECK_SZ; ++i) {
        std::cout << deck[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
