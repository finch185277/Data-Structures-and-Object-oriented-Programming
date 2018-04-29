#include <iostream>
#include <exception>
#include "0616214_Link_List.hpp" // .hpp for C++, .h for C
// using namespace std; // no need

//--------- <Node ---------------
template < typename T >
Int_Node<T>::Int_Node()
{
        this->pre = nullptr;
        this->next = nullptr;
        this->value = 0;
}

template < typename T >
Int_Node<T>::Int_Node(T value)
{
        this->pre = nullptr;
        this->next = nullptr;
        this->value = value;
}
//-------- Node> ------------------

//------------- <Link_List ---------
// public:
template < typename T >
Link_List<T>::Link_List()
        : size(0), head(nullptr), tail(nullptr)
// default constructor
{
}
template < typename T >
Link_List<T>::Link_List(const Link_List &rhs)
// copy constructor
{
        (*this) = rhs;
}
template < typename T >
Link_List<T>::~Link_List()
{
        delete head;
        delete tail;
}
//------------- Link_List> ---------

//------------- <func --------------
template < typename T >
int Link_List<T>::getSize() const
{
        return size;
}
template < typename T >
const Link_List<T> &Link_List<T>::operator=(const Link_List<T> &rhs) // rhs
// assignment operator
{
        Int_Node<T> *new_head = nullptr;
        Int_Node<T> *new_tail = nullptr;
        Int_Node<T> *nptr = rhs.head;

        while(nptr != nullptr)
        {
                Int_Node<T> *new_node = new Int_Node<T>(nptr->value);
                if(new_head == nullptr)
                {
                        new_head = new_node;
                        new_tail = new_node;
                }
                else
                {
                        new_tail->next = new_node;
                        new_tail->next->pre = new_tail;
                        new_tail = new_tail->next;
                }
                nptr = nptr->next;
        }
        this->head = new_head;
        this->tail = new_tail;
        this->size = rhs.getSize();
        return *this;
}
template < typename T >
bool Link_List<T>::operator==(const Link_List &rhs) const
// equality operator
{
        if(this->size != rhs.getSize()) return false;

        Int_Node<T> *n1 = this->head;
        Int_Node<T> *n2 = rhs.head;
        while(n1 != nullptr && n2 != nullptr) {
                if(n1->value != n2->value) return false;
                n1 = n1->next;
                n2 = n2->next;
        }
        return true;

}
// bool Link_List::operator!=(const Link_List &right) const
// // inequality operator
// {
//         return !(*this == right);
// }

template < typename T >
T &Link_List<T>::operator[](int index)
// subscript operator for non-const objects
{
        if(index > getSize() || index < 0) {
                std::cerr << "\nError: index " << index
                          << " out of range" << std::endl;
                exit(1); // terminate program; index out of range
        } else {
                Int_Node<T> *nptr = this->head;
                for(int i = 0; i < index; i++) {
                        nptr = nptr->next;
                }
                return nptr->value;
        }
}
template < typename T >
T Link_List<T>::operator[](int index) const
// subscript operator for const objects
{
        if(index > getSize() || index < 0) {
                std::cerr << "\nError: index " << index
                          << " out of range" << std::endl;
                exit(1); // terminate program; index out of range
        } else {
                Int_Node<T> *nptr = this->head;
                for(int i = 0; i < index; i++) {
                        nptr = nptr->next;
                }
                return nptr->value;
        }
}
//----------------- func> ---------------------

//----------------- <def func --------------------
template < typename T >
bool Link_List< T >::insert_node(T value)
// insert an integer at the back of link list
{
        try{
                Int_Node<T> *new_node = new Int_Node<T>(value);
                if(this->size == 0) {
                        this->head = new_node;
                        this->tail = new_node;
                } else {
                        this->tail->next = new_node;
                        this->tail->next->pre = this->tail;
                        this->tail = this->tail->next;
                }
                this->size++;
                return true;
        } catch(...) {
                return false;
        }
}
template < typename T >
bool Link_List<T>::delete_node()
// delete the last node
{
        try{
                Int_Node<T> *nptr = this->tail;
                nptr->pre->next = nullptr;
                delete nptr;
                this->size--;
                return true;
        } catch (...) {
                return false;
        }
}
template < typename T >
bool Link_List< T >::insert_node(int index, T value)
// insert an integer after the i_th position
{
        try{
                Int_Node<T> *new_node = new Int_Node<T>(value);
                Int_Node<T> *nptr = this->head;
                for(int i = 0; i < index; i++) {
                        nptr = nptr->next;
                }
                nptr->pre->next = new_node;
                new_node->pre = nptr->pre;
                new_node->next = nptr;
                nptr->pre = new_node;
                this->size++;
                return true;
        }
        catch(std::exception &) {
                return false;
        }
}
template < typename T >
bool Link_List<T>::delete_node(int index)
// delete the i_th node
// pointer to the first and the last element of Link_List
{
        try{
                Int_Node<T> *nptr = this->head;
                for(int i = 0; i < index; i++) {
                        nptr = nptr->next;
                }
                nptr->pre->next = nptr->next;
                nptr->next->pre = nptr->pre;
                delete nptr;
                this->size--;
                return true;
        }
        catch(...) {
                return false;
        }
}
//-------------- def func> -------------------------

//-------------- <IO --------------------
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
//-------------- IO> --------------------
