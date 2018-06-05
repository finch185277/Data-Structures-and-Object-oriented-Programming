#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main()
{
    int input;
    while (std::cin >> input && input > 0) {
        std::vector<int> nums;
        int flc = 0;
        while (input--) {
            int tmp;
            std::cin >> tmp;
            nums.push_back(tmp);
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    std::swap(nums[j], nums[j + 1]);
                    flc++;
                }
            }
        }
        std::cout << "Minimum exchange operations : " << flc << '\n';
    }
    return 0;
}
