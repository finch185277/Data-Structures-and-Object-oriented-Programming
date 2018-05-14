#pragma GCC optimize("O2") // 俞大大好強 我是小菜雞 btw,inline是啥阿
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>

// namespace {
// unsigned const MAXSIZE = 10000;
// };

class HashTable {
private:
    static const int MAXSIZE = 9973;
    struct data {
        std::string key = "", gender = "";
        int height = 0, weight = 0;
        data* next = nullptr;

        inline const std::string& getGender() const { return gender; }
        inline const int& getHeight() const { return height; }
        inline const int& getWeight() const { return weight; }
    };
    data* table[MAXSIZE];

public:
    HashTable()
    {
        for (int i = 0; i < MAXSIZE; i++) {
            data* newdata = new data;
            table[i] = newdata;
        }
    }
    inline void addItem(std::string k, std::string g, int h, int w)
    {
        int index = hash(k);

        if (table[index]->key == "") {
            table[index]->key = k;
            table[index]->gender = g;
            table[index]->height = h;
            table[index]->weight = w;
        } else {
            data* new_data = new data;

            new_data->key = k;
            new_data->gender = g;
            new_data->height = h;
            new_data->weight = w;

            // insert from head
            new_data->next = table[index];
            table[index] = new_data;
        }
    }
    inline const data& operator[](std::string k) const
    {
        int index = hash(k);
        data* d_ptr = table[index];

        if (d_ptr->key == k)
            return *d_ptr;

        while (d_ptr->next != nullptr) {
            d_ptr = d_ptr->next;

            if (d_ptr->key == k)
                return *d_ptr;
        }
    }
    inline data& operator[](std::string k)
    {
        int index = hash(k);
        data* d_ptr = table[index];

        if (d_ptr->key == k)
            return *d_ptr;

        while (d_ptr->next != nullptr) {
            d_ptr = d_ptr->next;

            if (d_ptr->key == k)
                return *d_ptr;
        }
    }
    inline const int hash(std::string k) const
    {
        int seed = 113;
        unsigned int index = 0;

        for (int i = 0; i < k.size(); i++)
            index = ((index * seed) + k[i]) % MAXSIZE;

        return (index % MAXSIZE);
    }
};

#endif
