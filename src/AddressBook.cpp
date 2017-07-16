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
      else
      {
          for(addrlist::iterator i = addresses_.begin(); i != addresses_.end(); ++i)
            if(i->recordId() == recordId)
                throw DuplicateId();
      }

      addresses_.push_back(addr);
      addresses_.back().recordId(recordId);

      return recordId;
}

AddressBook::addrlist::iterator AddressBook::getById(int recordId)throw (AddressNotFound)
{
    for(addrlist::iterator i = addresses_.begin(); i != addresses_.end(); ++i)
        if(i->recordId() == recordId)
                return i;
    throw AddressNotFound();
}

AddressBook::addrlist::const_iterator AddressBook::getById(int recordId)const throw (AddressNotFound)
{
    for(addrlist::const_iterator i = addresses_.begin(); i != addresses_.end(); ++i)
        if(i->recordId() == recordId)
                return i;
    throw AddressNotFound();
}

void AddressBook::eraseAddress(int recordId)throw(AddressNotFound)
{
    addrlist::iterator i = getById(recordId);
    addresses_.erase(i);
}

void AddressBook::replaceAddress(const Address& addr, int recordId)throw(AddressNotFound)
{
    if(recordId == 0)
        recordId = addr.recordId();

     addrlist::iterator i = getById(recordId);

    *i = addr;
    i->recordId(recordId);
}

const Address& AddressBook::getAddress(int recordId) const throw(AddressNotFound)
{
    return *getById(recordId);
}

void AddressBook::print() const
{
     for(addrlist::const_iterator i = addresses_.begin(); i != addresses_.end(); ++i)
     {
         const Address& a = *i;
         std::cout << "RecordId: " << a.recordId() << '\n'
                   << a.firstname() << ' ' << a.lastname() << '\n'
                   << a.address() << '\n' << a.phone() <<'\n'
                   << std::endl;
     }
}
