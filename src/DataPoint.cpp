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

Distance DataPoint::calcDistance(const DataPoint &x) const {
    double d = 0;
    for (size_t i = 0; i < data.size(); ++i) {d += abs(data[i] - x.data[i]);}
    return Distance(d, x.label);
}
