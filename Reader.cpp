#include "Reader.h"
#include <algorithm>

Reader::Reader(std::string file) {
    this->file = file;
    this->newStudents = 0;
    data = nullptr;
}

void Reader::UniversityData() {
    std::ifstream inFile("./resources/" + file);
    std::string trash;

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << file << std::endl;
        return;
    }

    inFile >> trash >> trash >> trash >> newStudents;
    std::cout << "New Students: " << newStudents << std::endl;

    while (true) {
        std::string initialSemester, probability, nextSemester;
        inFile >> initialSemester >> trash >> probability >> trash >> nextSemester;

        if (inFile.eof()) {
            break;
        }

        Data info(initialSemester, probability, nextSemester);
        dataVector.push_back(info);
    }

    inFile.close();
    sortData();

}

bool dataSorting(const Data& str1, const Data& str2) {

    if (str1.getNextSemester() == "Diploma" && str2.getNextSemester() != "Diploma")
        return false;
    if (str1.getNextSemester() != "Diploma" && str2.getNextSemester() == "Diploma")
        return true;

    if (str1.getInitialSemester() != str2.getInitialSemester()) {
        if (str1.getInitialSemester().size() == str2.getInitialSemester().size()) {
            return str1.getInitialSemester() < str2.getInitialSemester();
        }
        return str1.getInitialSemester().size() < str2.getInitialSemester().size();
    }

    if (str1.getNextSemester().size() == str2.getNextSemester().size()) {
        return str1.getNextSemester() < str2.getNextSemester();
    }

    return str1.getNextSemester().size() < str2.getNextSemester().size();
}

void Reader::sortData() {
    std::sort(dataVector.begin(), dataVector.end(), dataSorting);
}

std::vector<Data> Reader::getData() {
    return dataVector;
}


int Reader::getNewStudents() {
    return newStudents;
}
