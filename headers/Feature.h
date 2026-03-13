#ifndef _FEATURE_
#define _FEATURE_

#include "Column.h"
#include <string>
#include <vector>
#include <cmath>

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
        void scale() {
            int n = values.size();
            double sum = 0.0;
            for (int i = 0; i < n; ++i) {sum += values.at(i);}
            double mean = sum/n;
            double temp = 0.0;
            for (int i = 0; i < n; ++i) {temp += (values.at(i)-mean)*(values.at(i)-mean);}
            double stDev = std::sqrt(temp/(n-1));
            for (int i = 0; i < n; ++i) {values.at(i) = (values.at(i)-mean)/stDev;}
        }
};

#endif