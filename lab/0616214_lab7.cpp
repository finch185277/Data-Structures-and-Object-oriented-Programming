#include <iostream>
#include <vector>

int main() {
        int caseCount = 0;
        int countTemp = 1;
        std::cin >> caseCount;
        while(caseCount--) {
                int itemCount = 0;
                int upCount = 0;
                int downCount = 0;
                std::vector<int> wall;

                std::cin >> itemCount;
                for(int i = 0; i < itemCount; i++) {
                        int temp;
                        std::cin >> temp;
                        wall.push_back(temp);
                }
                for(auto it = wall.begin(); it != wall.end() - 1; it++) {
                        // using g++ -std=c++11 to compile "auto"
                        // but oj would break XD
                        if(*it > *(it+1)) {
                                downCount++;
                                continue;
                        }
                        if(*it < *(it+1)) {
                                upCount++;
                                continue;
                        }
                }
                std::cout << "Case " << countTemp++ << ":";
                std::cout << " " << upCount << " " << downCount << std::endl;
        }
        return 0;
}
