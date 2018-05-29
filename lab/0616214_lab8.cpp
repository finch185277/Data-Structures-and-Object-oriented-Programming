#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int test_count;
    std::string skip;
    std::cin >> test_count;
    std::getline(std::cin, skip);
    while (test_count--) {
        int opc = 0;
        std::string s;
        std::getline(std::cin, s);
        char opera[13] = { ' ' };
        int num[13] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*' || s[i] == '+')
                opera[opc++] = s[i];
            else
                num[opc] = num[opc] * 10 + s[i] - '0';
        }
        long long max = 1;
        long long min = 0;
        long long tmp = 0;
        //max + -> *
        tmp = num[0];
        for (int i = 0; i <= opc; i++) {
            if (opera[i] == '+') {
                tmp += num[i + 1];
            } else {
                max *= tmp;
                tmp = num[i + 1];
            }
        }
        //min * -> +
        tmp = num[0];
        for (int i = 0; i <= opc; i++) {
            if (opera[i] == '*') {
                tmp *= num[i + 1];
            } else {
                min += tmp;
                tmp = num[i + 1];
            }
        }
        std::cout << "The maximum and minimum are " << max << " and " << min << "." << '\n';
    }
}
