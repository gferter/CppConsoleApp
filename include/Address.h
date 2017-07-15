#ifndef ADDRESS_H
#define ADDRESS_H


class Address
{
    public:
        Address();

        ~Address();

        Address(const Address&);
        const Address& operator=(const Address&);

        const char* lastname() const {return lastname_;}
        void lastname(const char*);

        const char* firstname() const {return firstname_;}
        void firstname(const char*);

        const char* phone() const {return phone_;}
        void phone(const char*);

        const char* address() const {return address_;}
        void address(const char*);

    private:
        char* lastname_;
        char* firstname_;
        char* phone_;
        char* address_;

        char* dup(const char* s);
};

#endif // ADDRESS_H
