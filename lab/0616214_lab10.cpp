#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Die {
public:
    Die()
    {
        top = 1, bottom = 6;
        north = 2, south = 5;
        west = 3, east = 4;
    }
    void rotate(std::string& command)
    {
        if (command == "north") {
            std::swap(north, top);
            std::swap(south, bottom);
            std::swap(bottom, top);
        } else if (command == "south") {
            std::swap(south, top);
            std::swap(north, bottom);
            std::swap(bottom, top);
        } else if (command == "west") {
            std::swap(west, top);
            std::swap(east, bottom);
            std::swap(bottom, top);
        } else if (command == "east") {
            std::swap(east, top);
            std::swap(west, bottom);
            std::swap(bottom, top);
        }
    }
    int top, bottom;
    int north, south;
    int west, east;
};
int main()
{
    int cmdc;
    while (std::cin >> cmdc && cmdc > 0) {
        Die dice;
        std::string s;
        while (cmdc--) {
            std::cin >> s;
            dice.rotate(s);
        }
        std::cout << dice.top << '\n';
    }
}
