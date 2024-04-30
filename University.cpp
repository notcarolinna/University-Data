#include "Reader.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

void gaussianElimination(std::vector<std::vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size() - 1;

    for (int i = 0; i < numRows - 1; ++i) {
        double maxPivot = std::abs(matrix[i][i]);
        int maxRowIndex = i;
        for (int k = i + 1; k < numRows; ++k) {
            if (std::abs(matrix[k][i]) > maxPivot) {
                maxPivot = std::abs(matrix[k][i]);
                maxRowIndex = k;
            }
        }

        // Trocar a linha atual pela linha com o pivô máximo
        if (maxRowIndex != i) {
            std::swap(matrix[i], matrix[maxRowIndex]);
        }

        // Eliminação gaussiana
        for (int k = i + 1; k < numRows; ++k) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < numCols; ++j) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Backsubstitution
    for (int i = numRows - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < numCols; ++j) {
            sum += matrix[i][j] * matrix[j][numCols];
        }
        matrix[i][numCols] = (matrix[i][numCols] - sum) / matrix[i][i];
    }

}

int main() {
    Reader reader("caso1.txt");
    reader.UniversityData();
    std::vector<Data> data = reader.getData();

    std::vector<std::vector<double>> matrix(data.size(), std::vector<double>(data.size() + 1, 0.0));
    for (size_t i = 0; i < data.size(); ++i) {
        matrix[i][i] = std::stod(data[i].getProbability());
        if (i < data.size() - 1) {
            matrix[i + 1][i] = std::stod(data[i].getProbability());
        }
    }
    matrix[data.size() - 1][data.size()] = 1.0;

    gaussianElimination(matrix);

    std::cout << std::fixed << std::setprecision(4);

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
