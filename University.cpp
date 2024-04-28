#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include "Reader.h"

std::vector<std::vector<double>> dataMatrix(const std::vector<Data>& data) {

    std::map<std::string, int> semesterID;
    int id = 1;
    for (const auto& item : data) {
        if (semesterID.find(item.getInitialSemester()) == semesterID.end()) {
            semesterID[item.getInitialSemester()] = id++;
        }
        if (semesterID.find(item.getNextSemester()) == semesterID.end()) {
            semesterID[item.getNextSemester()] = id++;
        }
    }

    int totalSemesters = semesterID.size();

    std::vector<std::vector<double>> transitionMatrix(totalSemesters + 1, std::vector<double>(totalSemesters + 1, 0.0));

    for (const auto& item : data) {
        int fromSemester = semesterID[item.getInitialSemester()];
        int toSemester = semesterID[item.getNextSemester()];
        double probability = std::stod(item.getProbability());
        transitionMatrix[toSemester][fromSemester] = probability; 
    }

    for (int i = 1; i <= totalSemesters; ++i) {
        double sum = 0.0;
        for (int j = 1; j <= totalSemesters; ++j) {
            sum += transitionMatrix[i][j];
        }
        transitionMatrix[i][i] = -sum;
    }

    return transitionMatrix;
}

void printTransitionMatrix(const std::vector<std::vector<double>>& matrix) {
    std::cout << std::setw(5) << " ";
    for (size_t i = 1; i < matrix.size(); ++i) { 
        std::cout << std::setw(10) << i;
    }
    std::cout << std::endl;

    for (size_t i = 1; i < matrix.size(); ++i) { 

        std::cout << std::setw(5) << i;

        for (size_t j = 1; j < matrix[i].size(); ++j) { 
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    Reader reader("caso1.txt");
    reader.UniversityData();
    std::vector<Data> data = reader.getData();

    std::vector<std::vector<double>> transitionMatrix = dataMatrix(data);

    std::cout << "Matrix:" << std::endl;
    printTransitionMatrix(transitionMatrix);

    return 0;
}
