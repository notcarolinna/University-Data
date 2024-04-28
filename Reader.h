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
    int totalStudents;
    int graduatedStudents;

public:
    Reader();
    Reader(std::string file);
    void UniversityData();

    std::vector<Data> getData();
    void sortData();

    int getNewStudents();
    int getTotalStudents();
    int getGraduatedStudents();

};
