#include <iostream>

#include "AddressBook.h"

int AddressBook::nextId_ = 1;

AddressBook::AddressBook()
{
    //ctor
}

AddressBook::~AddressBook()
{
    //dtor
}

 int AddressBook::insertAddress(const Address& addr, int recordId)throw (DuplicateId)
{
      if(recordId == 0)
        recordId =  nextId_++;
      else if(recordId > nextId_)
        nextId_ = recordId + 1;
      else if(getById(recordId) != notFound)
        throw DuplicateId();

      addresses_.push_back(addr);
      addresses_.back().recordId(recordId);

      return recordId;
}

void AddressBook::eraseAddress(int recordId)throw(AddressNotFound)
{
    int index = getById(recordId);
    if(index == notFound)
        throw AddressNotFound();

    addresses_[index] = addresses_.back();
    addresses_.pop_back();
}

void AddressBook::replaceAddress(const Address& addr, int recordId)throw(AddressNotFound)
{
    if(recordId == 0)
        recordId = addr.recordId();
    int index = getById(recordId);
    if(index == notFound)
        throw AddressNotFound();

    addresses_[index] = addr;
    addresses_[index].recordId(recordId);
}

const Address& AddressBook::getAddress(int recordId) const throw(AddressNotFound)
{
    int index = getById(recordId);
    if(index == notFound)
        throw AddressNotFound();

    return addresses_[index];
}

void AddressBook::print() const
{
     std::cout << "***************************************************\n";
     for(int i = 0; i < addresses_.size(); ++i)
     {
         const Address& a = addresses_[i];
         std::cout << "RecordId: " << a.recordId() << '\n'
                   << a.firstname() << ' ' << a.lastname() << '\n'
                   << a.address() << '\n' << a.phone() <<'\n'
                   << std::endl;
     }
}

int AddressBook::getById(int recordId) const
{
     for(int i = 0; i < addresses_.size(); ++i)
        if(addresses_[i].recordId() == recordId)
            return i;
     return notFound;
}
