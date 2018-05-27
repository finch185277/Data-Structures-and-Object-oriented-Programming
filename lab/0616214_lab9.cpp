// ref: https://github.com/selvpole/OOP_HW_practice/blob/master/Lab/Lab09_Pay_the_Price/0616221_lab9.cpp
#include <iostream>
#include <sstream>
#include <string>

const int max_price = 300;
long long ways[max_price + 1][max_price + 1];

void make_table()
{
    // make the table
    for (int i = 0; i <= max_price; i++)
        ways[i][0] = 0;
    for (int j = 0; j <= max_price; j++)
        ways[0][j] = 1;
    for (int j = 1; j <= max_price; j++) {
        for (int i = j; i <= max_price; i++) {
            if (i - j < j)
                ways[i][j] = ways[i - j][i - j] + ways[i][j - 1];
            else
                ways[i][j] = ways[i - j][j] + ways[i][j - 1];
        }
    }
}
int main()
{
    make_table();
    std::string s;
    while (getline(std::cin, s)) {
        std::stringstream ss(s);
        int n, l1 = -1, l2 = -1;
        ss >> n;
        ss >> l1;
        ss >> l2;
        l2 > n ? l2 = n : l2 = l2;
        l1 > n&& l2 >= 0 ? l1 = n + 1 : l1 = l1;
        l1 > n&& l2 < 0 ? l1 = n : l1 = l1;
        if (l2 >= 0 && l1 == 0) // in case (l1 - 1) < 0
            std::cout << ways[n][l2] << '\n';
        else if (l2 >= 0)
            std::cout << ways[n][l2] - ways[n][l1 - 1] << '\n';
        else if (l1 >= 0)
            std::cout << ways[n][l1] << '\n';
        else
            std::cout << ways[n][n] << '\n';
    }
}
