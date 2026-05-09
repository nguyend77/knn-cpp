#ifndef __DATAPOINT__
#define __DATAPOINT__

#include "Distance.h"
#include <string>
#include <vector>
using namespace std;

class DataPoint {
    private:
        string label;
        vector<float> data;
    public:
        DataPoint(string& label, vector<float>& data);
        string getLabel() const;
        void setLabel(string label);
        const vector<float>& getData() const;
        void setData(int i, float val);
        Distance calcDistance(const DataPoint& x) const;
};

#endif
