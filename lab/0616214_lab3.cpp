#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    int a, b, test_count = 1;
    bool flag = false;
    while (std::cin >> a >> b && a > 0 && b > 0) {
        char origin[101][101], ans[101][101];
        memset(ans, '0', sizeof ans);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                std::cin >> origin[i][j];
            }
        }
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (origin[i][j] == '*')
                    ans[i][j] = '*';
                else {
                    if (origin[i + 1][j] == '*' && i + 1 < a)
                        ans[i][j]++;
                    if (origin[i - 1][j] == '*' && i - 1 >= 0)
                        ans[i][j]++;
                    if (origin[i][j + 1] == '*' && j + 1 < b)
                        ans[i][j]++;
                    if (origin[i][j - 1] == '*' && j - 1 >= 0)
                        ans[i][j]++;

                    if (origin[i + 1][j + 1] == '*' && i + 1 < a && j + 1 < b)
                        ans[i][j]++;
                    if (origin[i + 1][j - 1] == '*' && i + 1 < a && j - 1 >= 0)
                        ans[i][j]++;
                    if (origin[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 < b)
                        ans[i][j]++;
                    if (origin[i - 1][j - 1] == '*' && i - 1 >= 0 && j - 1 >= 0)
                        ans[i][j]++;
                }
            }
        }

        if (flag)
            std::cout << '\n';
        std::cout << "Field #" << test_count++ << ":" << '\n';
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                std::cout << ans[i][j];
            }
            std::cout << '\n';
        }
        flag = true;
    }
    return 0;
}
