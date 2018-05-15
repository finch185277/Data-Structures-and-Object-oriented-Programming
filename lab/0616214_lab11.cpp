// ref: https://github.com/david-perez/competitive-programming/blob/master/UVa/010912.cpp

#include <cstring> // memset
#include <iostream>
#include <string>

static int dp[27][352][27];

int hash(int L, int S, int c)
// L for length
// S for sum
// c for the first (header) smallest char
{
    if (L == 0 && S == 0)
        return 1;
    if (L == 0 || S == 0 || c > S)
        return 0;

    if (dp[L][S][c] != -1)
        return dp[L][S][c];

    int colls = 0;
    for (int i = c + 1; i <= 26; i++)
        colls += hash(L - 1, S - i, i);

    return dp[L][S][c] = colls;
}
int main()
{
    memset(dp, -1, sizeof dp);
    int L, S, case_count = 1;
    while (std::cin >> L >> S && !(L == 0 && S == 0)) {
        if (L > 26 || S > 351) {
            // 351 for 1+2+...+26 = 351
            int res = 0;
            std::cout << "Case " << case_count++;
            std::cout << ": " << res << std::endl;
        } else {
            int res = hash(L, S, 0);
            std::cout << "Case " << case_count++;
            std::cout << ": " << res << std::endl;
        }
    }
    return 0;
}
