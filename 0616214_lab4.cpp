#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long int case_count = 0, N = 0, row = 0, column = 0, initial = 0;
        char t1, t2;
        bool flag;

        cin >> case_count;

        initial = case_count;
        while(case_count--)
        {
                cin >> t1 >> t2 >> N;

                long long int arr[N+1][N+1];
                flag = true;

                for(row = 1; row <= N; row++)
                {
                        for(column = 1; column <= N; column++)
                        {
                                cin >> arr[row][column];
                                if(arr[row][column] < 0)
                                        flag = false;
                        }
                }

                for(row = 1; row <= N; row++)
                {
                        for(column = 1; column <= N; column++)
                        {
                                if(arr[row][column] != arr[N-row+1][N-column+1]) {
                                        flag = false;
                                        break;
                                }
                        }
                }
                cout << "Test #" << initial - case_count;

                if(flag)
                        cout << ": Symmetric." << endl;
                else
                        cout << ": Non-symmetric." << endl;
        }
        return 0;
}
