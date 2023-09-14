#include <iostream>
#include <sstream>

int main()
{
    std::string line;
    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        int H, U, D, F; ss >> H >> U >> D >> F;
        if (H == 0) break; // 0 0 0 0
        double p = 0;
        int i;
        for (i = 1; p >= 0 && p < H; ++i) {
            p += U - static_cast<double>(F/100.0 * U)*(i - 1); // day
            // std::cout << "p: " << p << std::endl;
            if (p > H) {
                std::cout << "success on day " << i << std::endl;
                break;
            }
            p -= D; // night
            if (p < 0) {
                std::cout << "failure on day " << i << std::endl;
                break;
            }
            // std::cout << "p: " << p << std::endl;
            // std::cout << "------------------" << std::endl;
        }
    }
    return(0);
}
