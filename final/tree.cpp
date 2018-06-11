#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> tree;
    tree.push_back(0);
    std::string nums, skip;
    std::getline(std::cin, nums);
    std::stringstream ss(nums);
    for (int tmp; ss >> tmp;) {
        tree.push_back(tmp);
    }
    std::string order;
    while (std::cin >> order && order[0] != '#') {
        int index = 1;
        for (int i = 0; i < order.size(); i++) {
            if (order[i] == 'L')
                index = index * 2;
            else if (order[i] == 'R')
                index = index * 2 + 1;
            else
                break;
        }
        if (index < tree.size())
            std::cout << tree[index] << '\n';
        else
            std::cout << "Wrong order" << '\n';
    }
}
