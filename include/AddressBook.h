#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include<list>
#include "Address.h"

bool operator==(const Address&, const Address&);
bool operator<(const Address&, const Address&);

#include<utility>
using namespace std::rel_ops;

class AddressBook
{
    public:
        AddressBook();
        ~AddressBook();

        class AddressNotFound {};
        class DuplicateId {};

        int insertAddress(const Address& addr, int recordId = 0) throw (DuplicateId);
        void eraseAddress(int recordId) throw(AddressNotFound);
        void replaceAddress(const Address& addr, int recordId = 0) throw (AddressNotFound);
        const Address& getAddress(int recordId) const throw (AddressNotFound);

        void print() const;

    private:
        AddressBook(const AddressBook&);
        AddressBook& operator=(const AddressBook&);

        static int nextId_;

        typedef std::list<Address> addrlist;
        addrlist addresses_;

        addrlist::iterator getById(int recordId)throw (AddressNotFound);
        addrlist::const_iterator getById(int recordId)const throw (AddressNotFound);
};

#endif // ADDRESSBOOK_H
