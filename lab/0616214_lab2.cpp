#include <cstring>
#include <iostream>
#include <sstream>
#include <string>

static bool is_square[100001];
void build()
{
    memset(is_square, false, sizeof is_square);
    for (int i = 0; i * i < 100001; i++) {
        is_square[i * i] = true;
    }
}
int main()
{
    build();
    int a, b;
    while (std::cin >> a >> b && a > 0 && b > 0) {
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (is_square[i])
                count++;
        }
        std::cout << count << '\n';
    }
    return 0;
}
