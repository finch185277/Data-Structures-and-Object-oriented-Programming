#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long int case_count, N, row, column, initial;
        char t1, t2;
        bool flag;

        cin >> case_count;

        initial = case_count;
        while(case_count--)
        {
                cin >> t1 >> t2 >> N;
                vector<vector<long long int> > matrix(N+1, vector<long long int>(N+1, 0));
                flag = true;

                for(row = 1; row <= N; row++)
                {
                        for(column = 1; column <= N; column++)
                        {
                                cin >> matrix.at(row).at(column);
                                if(matrix.at(row).at(column) < 0)
                                        flag = false;
                        }
                }

                for(row = 1; row <= N; row++)
                {
                        for(column = 1; column <= N; column++)
                        {
                                if(matrix.at(row).at(column) != matrix.at(N-row+1).at(N-column+1)) {
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
