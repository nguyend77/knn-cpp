#include "KNN.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

string inputFileName() {
    string filename;
    cout << "\nEnter absolute path to dataset (.csv): \n";
    getline(cin, filename);
    return filename;
}

string inputTarget() {
    string target;
    cout << "\nEnter target variable: \n";
    getline(cin, target);
    return target;
}

vector<string> inputFeatures() {
    vector<string> features;
    string line;
    string feature;
    cout << "\nEnter feature variables (comma separated): \n";
    getline(cin, line);
    stringstream ss(line);
    while (getline(ss, feature, ',')) {features.push_back(feature);}
    return features;
}

double inputTrainTestSplit() {
    double trainSize;
    cout << "\nEnter train proportion as a decimal: ";
    cin >> trainSize;
    return trainSize;
}

int inputK() {
    int k;
    cout << "\nEnter k: ";
    cin >> k;
    return k;
}

int main() {
    cout << "\n";
    cout << "#######################################################\n";
    cout << "# C++ implementation for kNN classification algorithm #\n";
    cout << "#######################################################\n";
    DataFrame df;
    string filename = inputFileName();
    string target = inputTarget();
    vector<string> features = inputFeatures();
    df.readCSV(filename, target, features);
    df.standardScaler();
    double trainSize = inputTrainTestSplit();
    df.splitTrainTest(trainSize);
    int k = inputK();
    KNN classifier(k, df);
    auto start = std::chrono::steady_clock::now();
    classifier.predict();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "\nExecution time: " << duration.count() << " ms" << endl;
    classifier.reportAccuracy();
    return 0;
}
