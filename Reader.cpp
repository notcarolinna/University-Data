#include "Reader.h"

Reader::Reader() {}

Reader::Reader(std::string file) {
    this->file = file;
    this->newStudents = 0;
    this->totalStudents = 0;
    this->graduatedStudents = 0;
}

void Reader::UniversityData() {
    std::ifstream inFile("./resources/" + file);
    std::string trash;

    if (!inFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << file << std::endl;
        return;
    }

    inFile >> trash >> trash >> trash >> newStudents;
    std::cout << "Novos alunos: " << newStudents << std::endl;

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
}



std::vector<Data> Reader::getData() {
    return dataVector;
}


int Reader::getNewStudents() {
    return newStudents;
}

int Reader::getTotalStudents() {
    return totalStudents;
}

int Reader::getGraduatedStudents() {
    return graduatedStudents;
}
