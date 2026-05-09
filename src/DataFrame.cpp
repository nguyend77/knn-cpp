#include "DataFrame.h"
#include "RandomGenerator.h"
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

int DataFrame::size() const {return count;}
const vector<DataPoint> &DataFrame::getObservations() const {return observations;}
const vector<size_t> &DataFrame::getTrain() const {return train;}
const vector<size_t> &DataFrame::getTest() const {return test;}

size_t DataFrame::linearSearch(string item, vector<string>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == item) {return i;}
    }
    return v.size();
}

void DataFrame::readCSV(const string& filename, const string& target, const vector<string>& features) {
    this->target = target;
    this->features = features;
    size_t targetIndex;
    vector<size_t> featureIndex;
    ifstream file(filename);
    string line;
    // get header on first line
    getline(file, line);
    stringstream ss(line);
    string cell;
    vector<std::string> row;
    while (getline(ss, cell, ',')) {row.push_back(cell);}
    targetIndex = linearSearch(target, row);
    for (const string& feat : features) {
        size_t i = linearSearch(feat, row);
        featureIndex.push_back(i);
    }
    // read subsequent lines for data entries
    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<std::string> row;
        while (getline(ss, cell, ',')) {row.push_back(cell);}
        string label = row[targetIndex];
        vector<float> data;
        for (const size_t& i: featureIndex) {
            float val = stod(row[i]);
            data.push_back(val);
        }
        observations.push_back(DataPoint(label, data));
        count++;
    }
}

void DataFrame::standardScaler() {
    int width = features.size();
    for (int i = 0; i < width; ++i) {
        float mean = 0;
        float stDev = 0;
        for (int j = 0; j < count; ++j) {mean += observations[j].getData()[i];}
        mean /= count;
        for (int j = 0; j < count; ++j) {
            float diff = observations[j].getData()[i] - mean;
            stDev += (diff*diff);
        }
        stDev = sqrt(stDev/count);
        for (int j = 0; j < count; ++j) {
            float scaled = (observations[j].getData()[i] - mean) / stDev;
            observations[j].setData(i, scaled);
        }
    }
}

void DataFrame::splitTrainTest(float trainSize) {
    vector<int> v;
    RandomGenerator rg;
    for (int i = 0; i < count; ++i) {v.push_back(i);}
    // Fisher-Yates shuffle
    for (int i = count - 1; i > 0; --i) {
        int j = rg.getInt(0,i);
        int temp = v[i];
        v[i]= v[j];
        v[j] = temp;
    }
    int split = count * trainSize;
    int i = 0;
    while (i < split) {
        train.push_back(v[i]);
        i++;
    }
    while (i < count) {
        test.push_back(v[i]);
        i++;
    }
}
