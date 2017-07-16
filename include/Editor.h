#ifndef EDITOR_H
#define EDITOR_H

#include <string>

class Editor
{
    public:
        enum editStatus{
            normal,
            finished,
            canceled
        };

        Editor():status_(normal){}

        bool editSingleLine(const std::string& prompt, std::string& value);
        bool editMultiLine(const std::string& prompt, std::string& value);

        editStatus status()const { return status_; }

    protected:

    private:
        editStatus status_;
};

#endif // EDITOR_H
