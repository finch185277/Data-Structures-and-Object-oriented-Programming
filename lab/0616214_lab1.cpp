// #include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void count_digit(std::string num, int SIZE)
{
    if (SIZE > 1) {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum = sum + num[i] - '0'; //string to int
        }
        std::string ts;
        std::stringstream tem;
        tem << sum;
        tem >> ts;
        count_digit(ts, ts.size());
    } else {
        std::cout << num[0] << "\n";
    }
}
int main()
{
    std::string num;
    while (std::cin >> num && num != "0") {
        count_digit(num, num.size());
    }
    return 0;
}
