#include "Distance.h"

Distance::Distance(float d, string label) {
    this->d = d;
    this->label = label;
}

string Distance::getLabel() const {return label;}

bool Distance::operator<(const Distance &other) const {return d < other.d;}
bool Distance::operator==(const Distance &other) const {return d == other.d;}
bool Distance::operator>(const Distance &other) const {return d > other.d;}
