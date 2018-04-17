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
                std::vector<int>::iterator it;

                std::cin >> itemCount;
                for(int i = 0; i < itemCount; i++) {
                        int temp;
                        std::cin >> temp;
                        wall.push_back(temp);
                }
                for(it = wall.begin(); it != wall.end() - 1; it++) {
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

