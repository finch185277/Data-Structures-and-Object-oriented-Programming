#include <bits/stdc++.h>
using namespace std;

int main()
{
        int a, b, count;
        int array[100001] = {0};

        for(int i = 1; i*i < 100001; i++)
        {
                array[i*i] = 1;
        }

        while(true)
        {
                cin >> a >> b;
                count = 0;

                if(a == 0 && b == 0)
                        break;

                for(int i = a; i <= b; i++)
                {
                        if(array[i] == 1)
                                count++;
                }

                cout << count << "\n";
        }
        return 0;
}
