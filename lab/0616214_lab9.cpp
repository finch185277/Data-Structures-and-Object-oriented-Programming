// ref: http://programming-study-notes.blogspot.tw/2014/04/uva-10313-pay-price.html
// ref: https://github.com/tommy5198/acm/blob/master/uva/uva10313.cpp
// ref: https://github.com/waiwai444/oj/blob/master/uva/10313%20-%20Pay%20the%20Price/10313.cpp
#include <iostream>
#include <sstream>

long long dp[301][301] = { 0 };

int main()
{
    dp[0][0] = 1;
    for (int i = 0; i < 301; i++)
        for (int j = 0; j + i < 301; j++)
            for (int k = 1; k < 301; k++)
                dp[j + i][k] += dp[j][k - 1];

    std::string line;
    int n[3];
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        int i = 0;
        while (ss >> n[i])
            i++;
        switch (i) {
        case 1:
            std::cout << dp[n[0]][n[0]] << std::endl;
            break;
        case 2:
            std::cout << dp[n[0]][n[1]] << std::endl;
            break;
        case 3:
            if (n[1] == 0)
                std::cout << dp[n[0]][n[2]] << std::endl;
            else
                std::cout << dp[n[0]][n[2]] - dp[n[0]][n[1] - 1] << std::endl;
            break;
        }
    }
}
