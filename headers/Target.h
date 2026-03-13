#ifndef _TARGET_
#define _TARGET_

#include "Column.h"
#include <string>
#include <vector>

class Target : public Column {
    private:
        std::vector<std::string> labels;
    public:
        Target(): Column() {};
        Target(const std::vector<std::vector<std::string>>& table, const std::string& target): Column(target) {
            int i;
            for (i = 0; i < table.at(0).size(); ++i) {
                if (table.at(0).at(i) == target) {break;}
            }
            for (int row = 1; row < table.size(); ++row) {
                labels.push_back(table.at(row).at(i));
            }
        }
        std::string getLabel(int& i) const {return labels.at(i);}
};

#endif