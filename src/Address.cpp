#include "Address.h"
#include <cstring>

Address::Address()
{
    lastname_[0] = firstname_[0] = phone_[0] = address_[0] = '\0';
}

void Address::lastname(const char* s)
{
    std::strncpy(lastname_, s, namelen-1);
    lastname_[namelen - 1] =  '\0';
}

void Address::firstname(const char* s)
{
    std::strncpy(firstname_, s, namelen-1);
    firstname_[namelen - 1] = '\0';
}

void Address::phone(const char* s)
{
    std::strncpy(phone_, s, phonelen-1);
    phone_[phonelen - 1] = '\0';
}

void Address::address(const char* s)
{
    std::strncpy(address_, s, addrlen-1);
    address_[addrlen - 1] = '\0';
}
