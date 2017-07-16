#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address
{
    public:
        Address(): recordId_(0){};

        int recordId() const {return recordId_;}
        void recordId(int i){recordId_ = i;}

        std::string lastname() const {return lastname_;}
        void lastname(const std::string&);

        std::string firstname() const {return firstname_;}
        void firstname(const std::string&);

        std::string phone() const {return phone_;}
        void phone(const std::string&);

        std::string address() const {return address_;}
        void address(const std::string&);

    private:
        int recordId_;
        std::string lastname_;
        std::string firstname_;
        std::string phone_;
        std::string address_;
};

#endif // ADDRESS_H
