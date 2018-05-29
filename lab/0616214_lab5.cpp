#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static int fab[5001][2001];

void build()
{
    memset(fab, 0, sizeof fab);
    fab[1][0] = 1;
    for (int i = 2; i < 5001; i++) {
        for (int j = 0; j < 2001; j++) {
            if (fab[i - 1][j] + fab[i - 2][j] > 0) {
                fab[i][j] += fab[i - 1][j] + fab[i - 2][j];
                fab[i][j + 1] += fab[i][j] / 10;
                fab[i][j] %= 10;
            } else
                continue;
        }
    }
}

int main()
{
    int num;
    build();
    while (std::cin >> num) {
        int digit = 2000;
        for (; digit >= 0; digit--) {
            if (fab[num][digit] > 0)
                break;
        }
        digit++;
        std::cout << "The Fibonacci number for " << num << " is ";
        if (digit == 0)
            std::cout << '0';
        else {
            for (; digit > 0; digit--) {
                std::cout << fab[num][digit - 1];
            }
        }
        std::cout << '\n';
    }
    return 0;
}
