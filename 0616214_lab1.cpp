#include <bits/stdc++.h>
using namespace std;

void count_digit(string num, int SIZE)
{
        if(SIZE > 1)
        {
                int sum = 0;
                for(int i = 0; i < SIZE; i++)
                {
                        sum = sum + num[i] - '0'; //string to int
                }
                //string ts = to_string(sum); //QQ not work
                string ts;
                stringstream tem; //Why~
                tem << sum;
                tem >> ts;
                count_digit(ts, ts.size());
        }
        else
        {
                cout << num[0] << "\n";
        }
}
int main()
{
        string num;
        while(cin >> num && num != "0")
        {
                count_digit(num, num.size());
        }
        return 0;
}
