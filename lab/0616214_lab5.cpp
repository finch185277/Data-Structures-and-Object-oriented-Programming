#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

vector<vector<int> > v(5001, vector<int>(2001,0));

int main() {
        v.at(1).at(0) = 1;
        for(int i = 2; i <= 5000; i++) {
                for(int index = 0; index < 2000; index++) {
                        v.at(i).at(index) += v.at(i-1).at(index) + v.at(i-2).at(index);
                        v.at(i).at(index+1)+= v.at(i).at(index)/10;
                        v.at(i).at(index)%=10;
                }
        }
        int num;
        while (cin >> num) {

                cout << "The Fibonacci number for " << num << " is ";
                int dc = 0; // dc = digit_count
                for( dc = 1999; dc >= 0; dc-- )
                {
                        if( v.at(num).at(dc) != 0 )
                                break;
                }
                if(dc == -1) cout << "0";
                else {
                        for(; dc >= 0; dc--)
                                cout << v.at(num).at(dc);
                }
                cout << endl;

        }
        return 0;
}
