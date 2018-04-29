#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

template < typename T = int>
struct Int_Node
{
        Int_Node();
        Int_Node(T);
        T value;
        Int_Node<T> *pre, *next;
};

template < typename T = int>
class Link_List
{

public:
Link_List();                                            // default constructor
Link_List(const Link_List<T> &);                           // copy constructor
~Link_List();
int getSize() const;

const Link_List<T> &operator=(const Link_List<T> &);          // assignment operator
bool operator==(const Link_List<T> &) const;               // equality operator
bool operator!=(const Link_List<T> &right) const           // inequality operator
{
        return !(*this == right);
}

int &operator[](int index);                             // subscript operator for non-const objects
int operator[](int index) const;                        // subscript operator for const objects

bool insert_node(T value);                            // insert an integer at the back of link list
bool delete_node();                                     // delete the last node
bool insert_node(int index, T value);                 // insert an integer after the i_th position
bool delete_node(int index);                            // delete the i_th node

private:
int size;
Int_Node<T> *head, *tail;                                  // pointer to the first and the last element of Link_List
};
template <typename T = int>
std::ostream &operator<<(std::ostream &output, const Link_List<T> &list)
// print all integers in the list
{
        for(int i = 0; i < list.getSize(); i++) {
                output << list[i] << " ";
        }
        return output;
}
template <typename T = int>
std::istream &operator>>(std::istream &input, Link_List<T> &list)
// input a value at the back of the list, like insert_node(val);
{
        int new_value;
        input >> new_value;
        list.insert_node(new_value);
        return input;
}

#endif // LINK_LIST
