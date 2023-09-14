#include <cmath>
#include <iostream>

int main()
{
    constexpr int MAX = 3001;
    int i, n, A[MAX];
    while (std::cin >> n) {
        for (i = 0; i < n; ++i) {
            std::cin >> A[i];
        }
        int mark[MAX], jolly = 1;
        for (i = 1; i < n; ++i) {
            if (abs(A[i] - A[i - 1]) < n) {
                ++mark[abs(A[i] - A[i - 1])];
            }
        }

        for (int i = 1; i < n; ++i) {
            if (!mark[i]) {
                jolly = 0;
                break;
            }
        }

        if (jolly) {
            std::cout << "Jolly";
        } else {
            std::cout << "Not Jolly";
        }
        std::cout << std::endl;
    }
    return(0);
}
