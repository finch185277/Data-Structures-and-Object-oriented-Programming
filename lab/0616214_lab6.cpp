#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<long long> set;
    long long num;
    while (std::cin >> num) {
        set.push_back(num);
        std::sort(set.begin(), set.end());
        if (set.size() & 1) // if odd
        {
            std::cout << set.at(set.size() / 2) << '\n';
        } else {
            std::cout << (set.at(set.size() / 2) + set.at(set.size() / 2 - 1)) / 2 << '\n';
        }
    }
}
