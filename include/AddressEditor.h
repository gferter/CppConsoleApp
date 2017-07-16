#ifndef ADDRESSEDITOR_H
#define ADDRESSEDITOR_H

#include "Editor.h"
#include "Address.h"

class AddressEditor : public Editor
{
    public:
        AddressEditor();
        AddressEditor(const Address& a);

        bool edit();
        bool editPhone(const std::string& prompt, std::string& phone);
        Address addr()const { return addr_; }
        void addr(const Address& a) { addr_ = a; }

    private:
        AddressEditor(const AddressEditor&);
        const AddressEditor& operator=(const AddressEditor&);

        Address addr_;
};

#endif // ADDRESSEDITOR_H
