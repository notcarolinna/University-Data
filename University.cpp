#include "Reader.h"

void gausianElimination() {

}

int main() {

    Reader reader("caso1.txt");
    reader.UniversityData();
    std::vector<Data> data = reader.getData();

    for (const auto& item : data) {
        std::cout << "Initial Semester: " << item.getInitialSemester() << std::endl;
        std::cout << "Probability: " << item.getProbability() << std::endl;
        std::cout << "Next Semester: " << item.getNextSemester() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
