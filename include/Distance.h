#ifndef __DISTANCE__
#define __DISTANCE__

#include <string>
using namespace std;

class Distance {
    private:
        double d;
        string label;
    public:
        Distance(double d, string label);
        string getLabel() const;
        bool operator<(const Distance& other) const;
        bool operator==(const Distance& other) const;
        bool operator>(const Distance& other) const;
};

#endif
