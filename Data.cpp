#include "Data.h"

Data::Data(std::string initialSemester, std::string probability, std::string nextSemester) {
    this->initialSemester = initialSemester;
    this->probability = probability;
    this->nextSemester = nextSemester;
}

std::string Data::getInitialSemester() const {
    return initialSemester;
}

std::string Data::getProbability() const {
    return probability;
}

std::string Data::getNextSemester() const {
    return nextSemester;
}
