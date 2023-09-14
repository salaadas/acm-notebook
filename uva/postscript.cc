#include <cctype>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#define oo 10
#define PAGE_SZ (60)
std::vector<std::string> page(PAGE_SZ, std::string(PAGE_SZ, '.'));
#define C5_HEIGHT 5
#define C5_WIDTH 6
std::map<char, std::vector<std::string>> C5 = {
    {'A', {".***..", "*...*.", "*****.", "*...*.", "*...*."}}, {'B', {"****..", "*...*.", "****..", "*...*.", "****.."}},
    {'C', {".****.", "*...*.", "*.....", "*.....", ".****."}}, {'D', {"****..", "*...*.", "*...*.", "*...*.", "****.."}},
    {'E', {"*****.", "*.....", "***...", "*.....", "*****."}}, {'F', {"*****.", "*.....", "***...", "*.....", "*....."}},
    {'G', {".****.", "*.....", "*..**.", "*...*.", ".***.."}}, {'H', {"*...*.", "*...*.", "*****.", "*...*.", "*...*."}},
    {'I', {"*****.", "..*...", "..*...", "..*...", "*****."}}, {'J', {"..***.", "...*..", "...*..", "*..*..", ".**..."}},
    {'K', {"*...*.", "*..*..", "***...", "*..*..", "*...*."}}, {'L', {"*.....", "*.....", "*.....", "*.....", "*****."}},
    {'M', {"*...*.", "**.**.", "*.*.*.", "*...*.", "*...*."}}, {'N', {"*...*.", "**..*.", "*.*.*.", "*..**.", "*...*."}},
    {'O', {".***..", "*...*.", "*...*.", "*...*.", ".***.."}}, {'P', {"****..", "*...*.", "****..", "*.....", "*....."}},
    {'Q', {".***..", "*...*.", "*...*.", "*..**.", ".****."}}, {'R', {"****..", "*...*.", "****..", "*..*..", "*...*."}},
    {'S', {".****.", "*.....", ".***..", "....*.", "****.."}}, {'T', {"*****.", "*.*.*.", "..*...", "..*...", ".***.."}},
    {'U', {"*...*.", "*...*.", "*...*.", "*...*.", ".***.."}}, {'V', {"*...*.", "*...*.", ".*.*..", ".*.*..", "..*..."}},
    {'W', {"*...*.", "*...*.", "*.*.*.", "**.**.", "*...*."}}, {'X', {"*...*.", ".*.*..", "..*...", ".*.*..", "*...*."}},
    {'Y', {"*...*.", ".*.*..", "..*...", "..*...", "..*..."}}, {'Z', {"*****.", "...*..", "..*...", ".*....", "*****."}},
    {' ', {"......", "......", "......", "......", "......"}}
};

int main()
{
    while (true) {
        std::string cmd; std::cin >> cmd;
        std::string font, content;
        int row, col;
        int width; // width of the output content
        int initialPos;
        switch (cmd[1]) {
            case 'E': {
                goto end;
            } break;
            case 'C':
            case 'L':
            case 'R':
            case 'P': {
                if (cmd[1] == 'P') {
                    std::cin >> font >> row >> col;
                } else { // L R C
                    std::cin >> font >> row;
                }
                --row; // for 0-based indexing
                --col;
                std::getline(std::cin >> std::ws, content);
                content.erase(0, 1); // remove `|` from the input
                content.erase(content.length() - 1, 1);
                // std::cout << "font: " << font << std::endl;
                // std::cout << "row: " << row << std::endl;
                // std::cout << "col: " << col << std::endl;
                // std::cout << "content: " << "`" << content << "`" << std::endl;
                if (font == "C1") {
                    width = content.length();
                    if (0 <= row && row < PAGE_SZ) {
                        if (cmd[1] == 'P') {
                            initialPos = col;
                        } else if (cmd[1] == 'C') {
                            initialPos = (PAGE_SZ - width)/2;
                        } else if (cmd[1] == 'L') {
                            initialPos = 0;
                        } else if (cmd[1] == 'R') {
                            initialPos = PAGE_SZ - width;
                        }
                        for (int j = initialPos; j < initialPos+width && j < PAGE_SZ; ++j) {
                            if (j < 0) continue;
                            page[row][j] = content[j - initialPos];
                        }
                    }
                } else if (font == "C5") {
                    if (cmd[1] == 'P') {
                        initialPos = col;
                    } else if (cmd[1] == 'C') {
                        width = content.length() * C5_WIDTH;
                        initialPos = (PAGE_SZ - width)/2;
                    } else if (cmd[1] == 'L') {
                        initialPos = 0;
                    } else if (cmd[1] == 'R') {
                        width = content.length() * C5_WIDTH;
                        initialPos = PAGE_SZ - width;
                    }
                    for (int i = row; i < row+C5_HEIGHT && i < PAGE_SZ; ++i) {
                        // std::cout << "row: " << i << std::endl;
                        if (i < 0) continue;
                        for (int j = 0, offset = initialPos; j < static_cast<int>(content.length()); ++j, offset+=C5_WIDTH) {
                            std::string line = C5[content[j] == ' ' ? ' ' : toupper(content[j])][i-row];
                            for (int k = 0; k < static_cast<int>(line.length()) && k+offset < PAGE_SZ; ++k) {
                                if (k+offset < 0) continue;
                                page[i][k+offset] = line[k];
                            }
                        }
                    }
                } else {
                    std::cerr << "ERROR: " << font << " is not defined" << std::endl;
                    if (cmd[1] == 'P') {
                        std::cerr << "USAGE: .P [C1|C5] <row> <col> <content>" << std::endl;
                    } else {
                        std::cerr << "USAGE: ." << cmd[1] << " [C1|C5] <row> <content>" << std::endl;
                    }
                    std::cerr << std::flush;
                    break;
                }
            } break;
            case 'p' /* preview */: {
                for (std::string line : page) {
                    std::cout << line << std::endl;
                }
                std::cout << "------------------------PREVIEW-MODE------------------------" << std::endl;
            } break;
        }
    }
    end:
    for (std::string line : page) {
        std::cout << line << std::endl;
    }
    std::cout << "------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    return(0);
}
