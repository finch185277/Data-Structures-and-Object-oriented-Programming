#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static long long ways[301][301];

void build()
{
    memset(ways, 0, sizeof ways);
    ways[0][0] = 1;

    for (int j = 1; j < 301; j++) {
        for (int i = j; i < 301; i++) {
            if (i - j < j)
                ways[i][j] = ways[i - j][i - j] + ways[i][j - 1];
            else
                ways[i][j] = ways[i - j][j] + ways[i][j - 1];
        }
    }
}

int main()
{
    build();
    std::string s;
    while (std::getline(std::cin, s)) {
        int num, a = -1, b = -1;
        std::stringstream ss(s);
        ss >> num;
        ss >> a;
        ss >> b;
        b > num ? b = num : b = b;
        a > num&& b >= 0 ? a = num + 1 : a = a;
        a > num&& b < 0 ? a = num : a = a;

        if (b >= 0 && a == 0)
            std::cout << ways[num][b] << '\n';
        else if (b >= 0)
            std::cout << ways[num][b] - ways[num][a - 1] << '\n';
        else if (a >= 0)
            std::cout << ways[num][a] << '\n';
        else
            std::cout << ways[num][num] << '\n';
    }
    return 0;
}
