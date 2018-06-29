#ifndef __PLAY_HPP__ // for fun by @hare1039
#define __PLAY_HPP__

#include <array>
#include <thread>

struct Node {
    int getGender() { return 1; }
    int getHeight() { return 1; }
    int getWeight() { return 1; }
};

struct RBTree {
    static auto& memory_plus()
    {
        static std::array<unsigned int, 100000000 / 32> static_array{};
        return static_array;
    }

    static auto& memory_minus()
    {
        static std::array<unsigned int, 100000000 / 32> static_array{};
        return static_array;
    }

    bool insert(int i, std::string&, int, int)
    {
        auto&& memory = (i < 0) ? memory_minus() : memory_plus();
        unsigned int ui = (i < 0) ? -i : i;
        int where = ui / 32;
        int shift = ui % 32;
        auto&& v = (memory[where] >> shift) & 1;
        if (v)
            return false;

        using namespace std::literals;
        // std::this_thread::sleep_for(0.0000001ns);
        memory[where] |= 1 << shift;
        return true;
    }

    Node& operator[](int)
    {
        static Node n;
        return n;
    }
};

#endif // __PLAY_HPP__
