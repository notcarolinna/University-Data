#pragma once
#include <string>

class Data {
private:
    std::string initialSemester;
    std::string probability;
    std::string nextSemester;

public:
    Data(std::string initialSemester, std::string probability, std::string nextSemester);
    std::string getInitialSemester() const; 
    std::string getProbability() const; 
    std::string getNextSemester() const; 
};
