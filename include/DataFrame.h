#ifndef __DATAFRAME__
#define __DATAFRAME__

#include "DataPoint.h"

class DataFrame {
    private:
        int count = 0;
        string target;
        vector<string> features;
        vector<DataPoint> observations;
        vector<size_t> train;
        vector<size_t> test;
    public:
        int size() const;
        const vector<DataPoint>& getObservations() const;
        const vector<size_t>& getTrain() const;
        const vector<size_t>& getTest() const;
        size_t linearSearch(string item, vector<string>& v);
        void readCSV(const string& filename, const string& target, const vector<string>& features);
        void standardScaler();
        void splitTrainTest(float trainSize = 0.8);
};

#endif
