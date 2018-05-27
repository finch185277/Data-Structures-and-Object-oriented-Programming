#include <array>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int case_count;
    std::string skip;
    std::cin >> case_count;
    std::getline(std::cin, skip); // to skip first line
    while (case_count--) {
        std::string s;
        std::getline(std::cin, s);
        int len = s.length(), opcnt = 0; // operator count
        std::array<long long, 13> num{ 0 }; // long long num[13] = { 0 };
        std::array<char, 13> opera{ '0' }; // char opera[13] = { 0 };
        std::vector<long long> v1;
        std::vector<long long> v2;

        for (int i = 0; i < len; i++) {
            if (s[i] == '*' || s[i] == '+')
                opera[opcnt++] = s[i];
            else
                num[opcnt] = num[opcnt] * 10 + s[i] - '0';
        }
        long long maximum = 1, minimum = 0, tmp = 0;

        // maximum
        for (int i = 0; i <= opcnt; i++) {
            if (i == 0)
                tmp = num[0];
            if (opera[i] == '+') {
                tmp += num[i + 1];
            } else {
                v1.push_back(tmp);
                tmp = num[i + 1];
            }
        }

        //minimum
        for (int i = 0; i <= opcnt; i++) {
            if (i == 0)
                tmp = num[0];
            if (opera[i] == '*') {
                tmp *= num[i + 1];
            } else {
                v2.push_back(tmp);
                tmp = num[i + 1];
            }
        }

        for (std::vector<long long>::iterator i = v1.begin(); i < v1.end(); i++) {
            maximum *= *i;
        }
        for (auto i = v2.begin(); i < v2.end(); i++)
            minimum += *i;

        std::cout << "The maximum and minimum are " << maximum;
        std::cout << " and " << minimum << '.' << '\n';
    }

    return 0;
}
