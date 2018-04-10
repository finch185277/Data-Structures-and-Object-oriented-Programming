#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>

int main() {
        long int n;
        std::vector<long int> output;
        while(!(std::cin >> n).eof()) {
                long int a, b;
                int length;

                output.push_back(n);
                length = output.size();

                sort(output.begin(), output.end()); // default is bool (i < j)
                if(length & 1) {  // if odd (bitwise is hard to read XD)
                        std::cout << output.at(length / 2) << std::endl;
                }
                else{
                        a = output.at((length / 2) - 1);
                        b = output.at(length / 2) + a; // sum of two int
                        std::cout << (b >> 1) << std::endl;
                }
        }
        return 0;
}
