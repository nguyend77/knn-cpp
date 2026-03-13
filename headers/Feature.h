#ifndef _FEATURE_
#define _FEATURE_

#include "Column.h"
#include <string>
#include <vector>

class Feature : public Column {
    private:
        std::vector<double> values;
    public:
        Feature(): Column() {};
        Feature(const std::vector<std::vector<std::string>>& table, const std::string& feature): Column(feature) {
            int i;
            for (i = 0; i < table.at(0).size(); ++i) {
                if (table.at(0).at(i) == feature) {break;}
            }
            for (int row = 1; row < table.size(); ++row) {
                double numeric = std::stod(table.at(row).at(i));
                values.push_back(numeric);
            }
        }
        double getValue(int& i) const {return values.at(i);}
};

#endif