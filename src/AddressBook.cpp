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

      addrlist::iterator i;
      for(i = addresses_.begin(); i != addresses_.end(); ++i)
        if(addr < *i)
            break;

      i = addresses_.insert(i, addr);
      i->recordId(recordId);

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

     eraseAddress(recordId);
     insertAddress(addr, recordId);
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

bool operator==(const Address& a1, const Address& a2)
{
   return(a1.lastname() == a2.lastname() &&
          a1.firstname() == a2.firstname() &&
          a1.phone() == a2.phone() &&
          a1.address() == a2.address());
}

bool operator<(const Address& a1, const Address& a2)
{
    if(a1.lastname() < a2.lastname())
            return true;
    else if(a2.lastname() < a1.lastname())
        return false;
    else
        return(a1.firstname() < a2.firstname());
}
