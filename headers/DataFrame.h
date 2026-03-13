#ifndef _DATAFRAME_
#define _DATAFRAME_

#include "Target.h"
#include "Feature.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class DataFrame {
    private:
        Target y;
        std::vector<Feature> x;
    public:
        void readCSV(std::string filename, const std::string& target, std::vector<std::string> drop = {}) {
            std::ifstream file(filename);
            std::vector<std::vector<std::string>> table;
            std::string line;
            while (std::getline(file, line)) {
                std::vector<std::string> row;
                std::stringstream ss(line);
                std::string cell;
                while (std::getline(ss, cell, ',')) {row.push_back(cell);}
                table.push_back(row);
            }
            file.close();
            y = Target(table, target);
            x.clear();
            for (int i = 0; i < table.at(0).size(); ++i) {
                std::string feature = table.at(0).at(i);
                bool ignore = false;
                if (feature == target) {ignore = true;}
                else {
                    for (int j = 0; j < drop.size(); j++) {
                        if (feature == drop.at(i)) {
                            ignore = true;
                            break;
                        }
                    }
                }
                if (!ignore) {x.push_back(Feature(table, feature));}
            }
        }
};

#endif