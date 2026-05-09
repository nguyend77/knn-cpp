#ifndef __DICTIONARY__
#define __DICTIONARY__

#include <vector>
#include <string>
using namespace std;

class Dictionary {
    private:
        int count = 0;
        vector<string> keys;
        vector<int> values;
    public:
        int size() const;
        void insert(string key);
        string getMax() const;
};

#endif
