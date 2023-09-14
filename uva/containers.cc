// NOT SOLVED YET
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

// max answer is 26 stacks
// as in 26 alphabet letters

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

int main()
{
    std::string line;
    std::vector<int> vis(1005, 0);
    while (std::cin >> line && line != "end") {
        std::fill(vis.begin(), vis.end(), 0);
        int count = 0;
        for (int i = 0; i < line.length(); ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                ++count;
                int prev = i;
                for (int j = i + 1; j < line.length(); ++j) {
                    if (!vis[j] && line[prev] >= line[j]) {
                        prev = j;
                        vis[j] = 1;
                    }
                }
            }
        }
        std::cout << "count: " << count << std::endl;
    }
    return(0);
}
