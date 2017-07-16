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
    editPhone("Phone Number", phone) &&
    editMultiLine("Address", address);

    if(status() == canceled)
        return false;

    addr_.lastname(lastname);
    addr_.firstname(firstname);
    addr_.phone(phone);
    addr_.address(address);

    return true;
}

bool AddressEditor::editPhone(const std::string& prompt, std::string& phone)
{
     if(!editSingleLine(prompt, phone))
        return false;

     static const std::string digits("0123456789");
     std::string::size_type suffix = phone.find_first_not_of(digits + "-()/. ");

     if(suffix == std::string::npos)
        suffix = phone.length();

     suffix =  phone.find_last_of(digits, suffix);
     if(suffix == std::string::npos)
        return true;
     ++suffix;

     std::string newnum;

     std::string::size_type p = phone.find_first_of(digits);
     while(p < suffix)
     {
         std::string::size_type q = phone.find_first_not_of(digits, p);

         newnum.append(phone, p, q - p);
         if(q == std::string::npos)
            break;
         p = phone.find_first_of(digits, q);
     }

     switch(newnum.length())
     {
     case 7:
        newnum.insert(3, 1, '-');
        break;
     case 8:
        if(newnum[0] != '1')
            return true;
        newnum.insert(4, 1, '-');
        newnum.insert(1, 1, '-');
        break;
     case 10:
        newnum.insert(6, 1, '-');
        newnum.insert(3, ") ");
        newnum.insert((int) 0, 1, '(');
        break;
     case 11:
        if(newnum[0] != '1')
            return true;
        newnum.insert(7, 1, '-');
        newnum.insert(4, ") ");
        newnum.insert(1, " (");
        break;
     default:
        return true;
     }

     phone.replace(0, suffix, newnum);
     return true;
}
