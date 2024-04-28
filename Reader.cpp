#include "Reader.h"
#include <algorithm>

Reader::Reader() {}

Reader::Reader(std::string file) {
    this->file = file;
    this->newStudents = 0;
    data = nullptr;
}

void Reader::UniversityData() {
    std::ifstream inFile("./resources/" + file);
    std::string trash;

    if (!inFile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << file << std::endl;
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

bool dataSorting(const Data& a, const Data& b) {

    // Para ordenar o arquivo, comparo o n�mero da primeira string de semestre com a segunda
    // Se a penultima linha for a string com diploma, troco ela de lugar com a ultima

    if (a.getNextSemester() == "Diploma" && b.getNextSemester() != "Diploma")
        return false;
    if (a.getNextSemester() != "Diploma" && b.getNextSemester() == "Diploma")
        return true;

    if (a.getInitialSemester() != b.getInitialSemester())
        return a.getInitialSemester() < b.getInitialSemester();
    if (a.getProbability() != b.getProbability())
        return a.getProbability() < b.getProbability();
    return a.getNextSemester() < b.getNextSemester();
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
