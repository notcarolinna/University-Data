#include "Reader.h"
#include <iomanip>

void gaussianElimination(std::vector<std::vector<double>>& matrix) {
    int numRows = matrix.size();
    int numCols = matrix[0].size() - 1;

    for (int i = 0; i < numRows - 1; i++) {
        double maxPivot = std::abs(matrix[i][i]);
        int maxRowIndex = i;
        for (int k = i + 1; k < numRows; k++) {
            if (std::abs(matrix[k][i]) > maxPivot) {
                maxPivot = std::abs(matrix[k][i]);
                maxRowIndex = k;
            }
        }

        if (maxRowIndex != i) {
            std::swap(matrix[i], matrix[maxRowIndex]);
        }

        for (int k = i + 1; k < numRows; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= numCols; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    for (int i = numRows - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < numCols; j++) {
            sum += matrix[i][j] * matrix[j][numCols];
        }
        matrix[i][numCols] = (matrix[i][numCols] - sum) / matrix[i][i];
    }
}

int main() {

    std::string filename;
    std::cout << "Enter the filename.txt: ";
    std::cin >> filename;

    Reader reader(filename);
    reader.UniversityData();
    std::vector<Data> data = reader.getData();

    int size = (data.size() / 2) + 1;

    std::vector<std::vector<double>> matrix(size, std::vector<double>(size + 1, 0.0));

    for (size_t i = 0; i < data.size(); i++) {
        if (i % 2 == 0) {
            matrix[i / 2][i / 2] = std::stod(data[i].getProbability()) - 1;
        }
        else {
            matrix[i / 2 + 1][i / 2] = std::stod(data[i].getProbability());
        }
    }

    matrix[size - 1][size - 1] = -1.0;
    matrix[0][size] = reader.getNewStudents() * (-1);

    gaussianElimination(matrix);

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\n\n";

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << std::setw(10) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    double total = 0.0;
    double totalStudents = 0.0;
    double graduatedStudents = matrix[matrix.size() - 1][matrix[0].size() - 1];

    for (int i = 0; i < matrix.size(); ++i) {
        total += matrix[i][matrix[i].size() - 1];
    }

    for (int i = 0; i < matrix.size() - 1; ++i) {
        totalStudents += matrix[i][matrix[i].size() - 1];
    }

    std::cout << "\nTotal of graduated students: " << std::fixed << std::setprecision(0) << graduatedStudents << std::endl;
    std::cout << "Total of students at university: " << std::fixed << std::setprecision(0) << totalStudents << std::endl;
    std::cout << "Total of students at university (including graduates): " << std::fixed << std::setprecision(0) << total << std::endl;

}

