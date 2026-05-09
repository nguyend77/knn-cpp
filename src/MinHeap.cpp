#include "MinHeap.h"

size_t MinHeap::parent(size_t i) {return (i - 1) / 2;}
size_t MinHeap::left(size_t i) {return (2 * i + 1);}
size_t MinHeap::right(size_t i) {return (2 * i + 2);}

void MinHeap::moveUp(size_t i) {
    while (i > 0 && heap[parent(i)] > heap[i]) {
        Distance temp = heap[i];
        heap[i] = heap[parent(i)];
        heap[parent(i)] = temp;
        i = parent(i);
    }
}

void MinHeap::moveDown(size_t i) {
    size_t smallest = i;
    size_t l = left(i);
    size_t r = right(i);
    if (l < heap.size() && heap[l] < heap[smallest]) {smallest = l;}
    if (r < heap.size() && heap[r] < heap[smallest]) {smallest = r;}
    if (smallest != i) {
        Distance temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        moveDown(smallest);
    }
}

void MinHeap::insert(Distance dist) {
    heap.push_back(dist);
    moveUp(heap.size()-1);
}

Distance MinHeap::getMin() {
    Distance root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) {moveDown(0);}
    return root;
}
