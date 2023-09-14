#include <iostream>
#include <string>

int main()
{
    int i = 0, req, prop;
    while (std::cin >> req >> prop) {
        if (req == 0 && prop == 0)
            break;
        ++i;
        std::string bestProp, throwAway;
        std::getline(std::cin, throwAway);
        double bestPrice = -1;
        double bestComp = 0;
        for (int a = 1; a <= req; ++a) {
            std::getline(std::cin, throwAway);
            // std::cout << ">" << throwAway << std::endl;
        }
        for (int a = 1; a <= prop; ++a) {
            std::string propName; std::getline(std::cin, propName);

            // std::cout << propName << std::endl;

            double price, meet; std::cin >> price >> meet;
            std::getline(std::cin, throwAway);
            if (meet/req > bestComp) {
                bestComp = meet/req;
                bestPrice = price;
                bestProp = propName;
            }
            for (int a = 1; a <= meet; ++a)
                std::getline(std::cin, throwAway);
        }
        std::cout << "RFP #" << i << std::endl;
        std::cout << bestProp << std::endl;
    }
    return(0);
}
