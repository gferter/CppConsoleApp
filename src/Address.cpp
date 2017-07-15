#include "Address.h"
#include <cstring>

Address::Address():
                    lastname_(new char [1]),
                    firstname_(new char [1]),
                    phone_(new char [1]),
                    address_(new char [1])
{
    lastname_[0] = firstname_[0] = phone_[0] = address_[0] = '\0';
}

Address::~Address()
{
    delete[] lastname_;
    delete[]  firstname_;
    delete[]  phone_;
    delete[]  address_;
}

char* Address::dup(const char* s)
{
    char* ret  = new char[strlen(s) + 1];
    strcpy(ret, s);
    return ret;
}

Address::Address(const Address& a2): lastname_(0), firstname_(0), phone_(0), address_(0)
{
    *this = a2;
}

const Address& Address::operator=(const Address& a2)
{
     if(this != &a2)
     {
         lastname(a2.lastname_);
         firstname(a2.firstname_);
         phone(a2.phone_);
         address(a2.address_);
     }

     return *this;
}

void Address::lastname(const char* s)
{
    if(lastname_ != s)
    {
        delete[] lastname_;
        lastname_ = dup(s);
    }
}

void Address::firstname(const char* s)
{
    if(firstname_ != s)
    {
        delete[] firstname_;
        firstname_ = dup(s);
    }
}

void Address::phone(const char* s)
{
    if(phone_ != s)
    {
        delete[] phone_;
        phone_ = dup(s);
    }
}

void Address::address(const char* s)
{
    if(address_ != s)
    {
        delete[] address_;
        address_ = dup(s);
    }
}
