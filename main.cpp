#include <iostream>

#include "Address.h"
#include "AddressEditor.h"

void dump(const Address& a)
{
    std::cout << "Record: " << a.recordId() << '\n'
              << a.firstname() << ' ' << a.lastname() << '\n'
              << a.address() << '\n' << a.phone() <<'\n'
              << std::endl;
}

int main()
{
    Address a;
    AddressEditor editor(a);
    while(a.lastname() != "done")
    {
        editor.edit();
        a = editor.addr();
        std::cout << std::endl;
        dump(a);
    }
    return 0;
}
