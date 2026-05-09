#include "DataPoint.h"
#include <cmath>
using namespace std;

DataPoint::DataPoint(string& label, vector<double>& data) {
    this->label = label;
    this->data = data;
}

string DataPoint::getLabel() const {return label;}
void DataPoint::setLabel(string label) {this->label = label;}

const vector<double>& DataPoint::getData() const {return data;}
void DataPoint::setData(int i, double val) {data[i] = val;}

Distance DataPoint::calcDistance(const DataPoint &x, char type) const {
    double d = 0;
    switch(type) {
        case 'm':
            for (size_t i = 0; i < data.size(); ++i) {d += abs(data[i] - x.data[i]);}
            break;
        case 'e':
            for (size_t i = 0; i < data.size(); ++i) {d += (data[i] - x.data[i])*(data[i] - x.data[i]);}
            break;
    }
    return Distance(d, x.label);
}
