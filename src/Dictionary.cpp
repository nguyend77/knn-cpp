#include "Dictionary.h"

int Dictionary::size() const {return count;}

void Dictionary::insert(string key) {
    for (int i = 0; i < count; ++i) {
        if (key == keys[i]) {
            values[i]++;
            return;
        }
    }
    keys.push_back(key);
    values.push_back(1);
    count++;
}

string Dictionary::getMax() const {
    string maxKey;
    int maxCount = 0;
    for (int i = 0; i < count; ++i) {
        if (values[i] > maxCount) {
            maxKey = keys[i];
            maxCount = values[i];
        }
    }
    return maxKey;
}
