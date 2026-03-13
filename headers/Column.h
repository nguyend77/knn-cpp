#ifndef _COLUMN_
#define _COLUMN_

#include <string>
#include <vector>

class Column {
    private:
        std::string name;
    public:
        Column() {}
        Column(const std::string& name): name(name) {}
        std::string setName(const std::string& name) {this->name = name;}
        std::string getName() const {return name;}
};

#endif