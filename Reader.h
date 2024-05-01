#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Data.h"

class Reader {
private:
    Data** data;
    std::string file;
    std::vector<Data> dataVector;
    int newStudents;

public:
    Reader(std::string file);
    void UniversityData();
    void sortData();

    int getNewStudents();
    std::vector<Data> getData();    

};