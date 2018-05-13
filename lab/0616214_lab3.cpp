#include <bits/stdc++.h>
using namespace std;

int main()
{
    int line;
    int column;
    char raw_field[200][200];
    char output_field[200][200];
    int testNum = 0;
    bool endline = false;
    int i;
    int j;

    while (cin >> line >> column) {
        for (i = 0; i < line; i++)
            for (j = 0; j < column; j++)
                output_field[i][j] = '0';

        for (i = 0; i < line; i++)
            for (j = 0; j < column; j++)
                cin >> raw_field[i][j];

        if ((line == 0) && (column == 0))
            break;

        for (i = 0; i < line; i++)
            for (j = 0; j < column; j++) {
                if (raw_field[i][j] == '*')
                    output_field[i][j] = '*';

                else {
                    if (raw_field[i + 1][j] == '*' && i + 1 <= line - 1)
                        output_field[i][j]++;
                    if (raw_field[i - 1][j] == '*' && i - 1 >= 0)
                        output_field[i][j]++;
                    if (raw_field[i][j + 1] == '*' && j + 1 <= column - 1)
                        output_field[i][j]++;
                    if (raw_field[i][j - 1] == '*' && j - 1 >= 0)
                        output_field[i][j]++;

                    if (raw_field[i + 1][j + 1] == '*' && i + 1 <= line - 1 && j + 1 <= column - 1)
                        output_field[i][j]++;
                    if (raw_field[i + 1][j - 1] == '*' && i + 1 <= line - 1 && j - 1 >= 0)
                        output_field[i][j]++;
                    if (raw_field[i - 1][j + 1] == '*' && i - 1 >= 0 && j + 1 <= column - 1)
                        output_field[i][j]++;
                    if (raw_field[i - 1][j - 1] == '*' && i - 1 >= 0 && j - 1 >= 0)
                        output_field[i][j]++;
                }
            }

        if (endline)
            cout << "\n";
        cout << "Field #" << ++testNum << ":"
             << "\n";
        for (int y = 0; y < line; y++) {
            for (int x = 0; x < column; x++) {
                cout << output_field[y][x];
            }
            cout << endl;
        }
        endline = true;
    }
    return 0;
}
