#include <iostream>

#include "AddressBook.h"

int main()
{
    AddressBook book;

    Address a;
    a.lastname("Smith");
    a.firstname("Joan");
    a.phone("(617) 555-9876");
    a.address("The Very Big Corporation \nSomewhere, MA 01000");

    Address b;
    b.lastname("Adams");
    b.firstname("Abigale");
    b.phone("(212) 555-3734");
    b.address("743 Broadway\nNew York, NY");

    Address c;
    c.lastname("Neighborhood Video");
    c.phone("555-FILM");

    int a_id = book.insertAddress(a);
    int b_id = book.insertAddress(b);
    int c_id = book.insertAddress(c);
    std::cout << "*** Three Address Entries ***\n";
    book.print();

    Address d;
    d.lastname("Adams");
    d.firstname("Abigale");
    d.phone("(508) 555-4466");
    d.address("1 Small St. \nMarlboro, MA 02100");

    int d_id = book.insertAddress(d);
    std::cout << "*** After adding a duplicate Abigale Adams ***\n";
    book.print();

    book.eraseAddress(a_id);
    std::cout << "*** After erasing Joan Smith ***\n";
    book.print();

    c.address("22 Main St. \nMy town,MA 02200");
    book.replaceAddress(c, c_id);
    std::cout << "*** After replacing Neighborhood Video ***\n";
    book.print();

    const Address& d2 = book.getAddress(d_id);
    std::cout << "*** Copy of d: ***\n"
              << d2.firstname() << ' ' << d2.lastname() << '\n'
              << d2.address() << '\n' << d2.phone() <<'\n'
              << std::endl;

    return 0;
}
