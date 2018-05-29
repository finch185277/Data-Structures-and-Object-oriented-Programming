#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int test_count, reg = 1;
    std::cin >> test_count;
    while (test_count--) {
        char skip1, skip2;
        int N;
        bool flag = true;
        std::cin >> skip1 >> skip2 >> N;
        long long mat[N + 1][N + 1];
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                std::cin >> mat[i][j];
                if (mat[i][j] < 0)
                    flag = false;
            }
        }
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (mat[i][j] != mat[N - i + 1][N - j + 1]) {
                    flag = false;
                    break;
                }
            }
        }
        std::cout << "Test #" << reg++ << ": ";
        if (flag)
            std::cout << "Symmetric." << '\n';
        else
            std::cout << "Non-symmetric." << '\n';
    }
}
