#include "KNN.h"
#include "MinHeap.h"
#include "Dictionary.h"
#include <iostream>

KNN::KNN(int k, const DataFrame& df) {
    this->k = k;
    dfPtr =&df;
}

void KNN::predict() {
    for (size_t i = 0; i < dfPtr->getTest().size(); ++i) {
        size_t testIndex = dfPtr->getTest()[i];
        DataPoint unknown = dfPtr->getObservations()[testIndex];
        MinHeap distanceHeap;
        for (size_t j = 0; j < dfPtr->getTrain().size(); ++j) {
            size_t learnIndex = dfPtr->getTrain()[j];
            DataPoint known = dfPtr->getObservations()[learnIndex];
            distanceHeap.insert(unknown.calcDistance(known));
        }
        Dictionary choices;
        for (int guess = 0; guess < k; ++guess) {
            string label = distanceHeap.getMin().getLabel();
            choices.insert(label);
        }
        prediction.push_back(choices.getMax());
    }
}

void KNN::reportAccuracy() {
    int numTrue = 0;
    size_t testSize = dfPtr->getTest().size();
    for (size_t i = 0; i < testSize; ++i) {
        size_t testIndex = dfPtr->getTest()[i];
        DataPoint unknown = dfPtr->getObservations()[testIndex];
        if (prediction[i] == unknown.getLabel()) {numTrue++;}
    }
    float accuracy = (100.0*numTrue) / testSize;
    cout << "\nAccuracy: " << accuracy << "% (" << numTrue << "/" << testSize << ")" << endl;
}
