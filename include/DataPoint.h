#ifndef __DATAPOINT__
#define __DATAPOINT__

#include "Distance.h"
#include <string>
#include <vector>
using namespace std;

class DataPoint {
    private:
        string label;
        vector<double> data;
    public:
        DataPoint(string& label, vector<double>& data);
        string getLabel() const;
        void setLabel(string label);
        const vector<double>& getData() const;
        void setData(int i, double val);
        Distance calcDistance(const DataPoint& x) const;
};

#endif
