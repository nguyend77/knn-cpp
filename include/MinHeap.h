#ifndef __MINHEAP__
#define __MINHEAP__

#include <vector>
#include "Distance.h"
using namespace std;

class MinHeap {
    private:
        vector<Distance> heap;
        size_t parent(size_t i);
        size_t left(size_t i);
        size_t right(size_t i);
        void moveUp(size_t i);
        void moveDown(size_t i);
    public:
        void insert(Distance dist);
        Distance getMin();
};

#endif