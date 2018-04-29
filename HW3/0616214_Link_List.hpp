#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
// using namespace std; // no need
// friend ostream istream no need

template < typename T = int>
struct Int_Node
{
        Int_Node();
        Int_Node(T);
        T value;
        Int_Node<T> *pre = nullptr, *next = nullptr;
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

T &operator[](int index);                             // subscript operator for non-const objects
T operator[](int index) const;                        // subscript operator for const objects

bool insert_node(T value);                            // insert an integer at the back of link list
bool delete_node();                                     // delete the last node
bool insert_node(int index, T value);                 // insert an integer after the i_th position
bool delete_node(int index);                            // delete the i_th node

private:
int size;
Int_Node<T> *head, *tail;                                  // pointer to the first and the last element of Link_List
};

#include "0616214_Link_List.cpp"
#endif // LINK_LIST
