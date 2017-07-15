#ifndef ADDRESS_H
#define ADDRESS_H


class Address
{
    public:
        Address();

        const char* lastname() const {return lastname_;}
        void lastname(const char*);

        const char* firstname() const {return firstname_;}
        void firstname(const char*);

        const char* phone() const {return phone_;}
        void phone(const char*);

        const char* address() const {return address_;}
        void address(const char*);

    private:
        enum {namelen = 16, phonelen = 16, addrlen = 100};

        char lastname_[namelen];
        char firstname_[namelen];
        char phone_[phonelen];
        char address_[addrlen];
};

#endif // ADDRESS_H
