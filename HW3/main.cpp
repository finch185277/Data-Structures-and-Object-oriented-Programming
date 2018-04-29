#include <iostream>

#include "0616214_Link_List.hpp"

// using namespace std; // no need

using type = float;

int main()
{

        // test default constructor
        Link_List<type> linkList1;

        // test copy constructor
        Link_List<type> linkList2(linkList1);

        // test getSize()
        std::cout<< "linkList2 Size: " << linkList2.getSize() << std::endl;

        // test insert_node(value), delete_node(), operator<<, operator>>

        Link_List<type> linkList3;
        std::cout<< "Enter a integer: ";
        std::cin >> linkList3;
        std::cout << "linkList3: "<< linkList3 << std::endl;

        linkList3.insert_node(11);
        linkList3.insert_node(12);
        linkList3.insert_node(13);
        linkList3.insert_node(14);
        linkList3.insert_node(3,17);
        std::cout<< "Insert Boolean: " << linkList3.insert_node(16) << std::endl;
        std::cout<< "linkList3: " << linkList3 << std::endl;

        std::cout<< "Delete Boolean: " << linkList3.delete_node() << std::endl;
        std::cout<< "linkList3: " << linkList3 << std::endl;

        // test assignment operator, equality operator, insert_node(index, value), delete_node(index)
        Link_List<type> linkList4 = linkList3;
        std::cout<< "linkList4: " << linkList4 << std::endl;

        std::cout<< "Insert Boolean: " << linkList4.insert_node(3, 17) << std::endl;
        std::cout<< "linkList4: " << linkList4 << std::endl;

        std::cout<< "Delete Boolean: " << linkList4.delete_node(4) << std::endl;
        std::cout<< "Equality Boolean: " << (linkList4==linkList3) << std::endl;
        std::cout<< "linkList4: " << linkList4 << std::endl;

        // test subscript operator []
        const Link_List<type> linkList5 = linkList4;
        std::cout<< "linkList4[1]: " << linkList4[1] << std::endl;
        std::cout<< "linkList5[1]: " << linkList5[1] << std::endl;

        return 0;
}
