#include <iostream>
#include <set>
#include <functional>

int main()
{
    int n; std::cin >> n;
    while (n--) {
        int b, sg, sb; std::cin >> b >> sg >> sb;
        std::multiset<int, std::greater<int>> bArmy, gArmy;
        int tmp;
        while (sg--) {
            std::cin >> tmp;
            gArmy.insert(tmp);
        }
        while (sb--){
            std::cin >> tmp;
            bArmy.insert(tmp);
        }
        while (bArmy.size() && gArmy.size()) {
            for (int i = 0; i < b && i < bArmy.size() && i < gArmy.size(); ++i) {
                int bv = *bArmy.begin(), gv = *gArmy.begin();
                bArmy.erase(bArmy.begin()); gArmy.erase(gArmy.begin());
                if (bv < gv) {
                    gv -= bv;
                    gArmy.insert(gv);
                } else if (bv > gv) {
                    bv -= gv;
                    bArmy.insert(bv);
                }
            }
        }
        if (bArmy.size()) {
            printf("blue wins\n");
            for (const int &i : bArmy)
                printf("%d\n", i);
        } else if (gArmy.size()) {
            printf("green wins\n");
            for (const int &i : gArmy)
                printf("%d\n", i);
        } else {
            printf("green and blue died\n");
        }
        printf("\n");
    }
    return(0);
}
