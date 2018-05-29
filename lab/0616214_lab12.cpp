// ref: https://blog.csdn.net/nameofcsdn/article/details/52268956
#include <cstring> // memset
#include <iostream>

static int sum[2750000];
// sum[n], n! has # of prime
// input = #, find n

// ex. input = 7, find n = 6
//     6!  = 6*5*4*3*2*1
//     ans = {6 = (3,2),5,(2,2),3,2}
//         + {5 = 5,(2,2),3,2}
//         + {4 = (2,2),3,2}
//         + {3 = 3,2} + {2 = 2}

bool is_prime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}
void build()
{
    memset(sum, 0, sizeof sum);
    for (int i = 2; i < 2750000; i++) {
        // first, count i has # of prime
        // ex. 12 = 2(2), 3(3), 2(4)
        // ex. 54 = 2(2), 3(3), 3(9), 3(27)

        // for (int j = i; j < 2750000; j += i)
        //     sum[j]++;
        // wrong (18 counted in 2, 3, 6, 9, 18)
        // true  (18 = 2(2), 3(3), 3(9))

        if (is_prime(i)) {
            long long m = i;
            while (m < 2750000) {
                for (int j = m; j < 2750000; j += m)
                    sum[j]++;
                m *= i;
            }
        }
    }
    // std::cout << sum[15] << ' ' << sum[16] << ' ' << sum[17] << ' ' << sum[18] << '\n';
    //              2, no 3             4                 1               3, no 5
    // std::cout << sum[5] << ' ' << sum[6] << ' ' << sum[7] << ' ' << sum[8] << '\n';
    //                1              2, no 3              1                3

    for (int i = 1; i < 2750000; i++)
        // second, for Factorial #
        sum[i] += sum[i - 1];
}
int main()
{
    build();
    int n;
    int case_count = 1;

    while (std::cin >> n && n >= 0) {
        int low, high, mid;
        std::cout << "Case " << case_count++ << ": ";
        low = 0, high = 2749999;
        while (low < high - 1) {
            mid = (low + high) / 2;
            if (sum[mid] < n)
                low = mid;
            else if (sum[mid] > n)
                high = mid;
            else
                break;
        }
        if (n == 0)
            mid = 0;
        if (sum[mid] == n)
            std::cout << mid << "!\n";
        else
            std::cout << "Not possible.\n";
    }
    return 0;
}
