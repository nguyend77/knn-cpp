#ifndef __KNN__
#define __KNN__

#include "DataFrame.h"

class KNN {
    private:
        int k;
        const DataFrame* dfPtr;
        vector<string> prediction;
    public:
        KNN(int k, const DataFrame& df);
        void predict(char distanceType = 'm');
        void reportAccuracy();
};

#endif
