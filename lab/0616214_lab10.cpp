// ref: http://knightzone.org/?p=3155

#include <iostream>
#include <string>

class Dice {
public:
    Dice()
    {
        top = 1;
        north = 2;
        west = 3;
        bottom = 6;
        south = 5;
        east = 4;
    }
    void rotate(std::string& command)
    {
        if (command == "north") {
            std::swap(top, north);
            std::swap(bottom, south);
            std::swap(top, bottom);
        } else if (command == "south") {
            std::swap(top, south);
            std::swap(bottom, north);
            std::swap(top, bottom);
        } else if (command == "east") {
            std::swap(top, east);
            std::swap(bottom, west);
            std::swap(top, bottom);
        } else if (command == "west") {
            std::swap(top, west);
            std::swap(bottom, east);
            std::swap(top, bottom);
        }
    }
    int top, bottom;
    int north, south;
    int east, west;
};

int main()
{
    int command_number;
    while (std::cin >> command_number && command_number != 0) {
        Dice dice;
        for (int i = 0; i < command_number; i++) {
            std::string command;
            std::cin >> command;
            dice.rotate(command);
        }
        std::cout << dice.top << std::endl;
    }
    return 0;
}
