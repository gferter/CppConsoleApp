#include "AddressEditor.h"

AddressEditor::AddressEditor()
{
    //ctor
}

AddressEditor::AddressEditor(const Address& a): addr_(a)
{
    //ctor
}

bool AddressEditor::edit()
{
    std::string lastname(addr_.lastname());
    std::string firstname(addr_.firstname());
    std::string phone(addr_.phone());
    std::string address(addr_.address());

    editSingleLine("Last name", lastname) &&
    editSingleLine("First name", firstname) &&
    editSingleLine("Phone Number", phone) &&
    editMultiLine("Address", address);

    if(status() == canceled)
        return false;

    addr_.lastname(lastname);
    addr_.firstname(firstname);
    addr_.phone(phone);
    addr_.address(address);

    return true;
}
