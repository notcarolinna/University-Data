# Student Flow Simulator

This code was developed to calculate the total number of students who will graduate at the end of the course and the total number of students enrolled in a university, using the Gauss elimination method. The data required for the analysis is obtained from a text file provided by the user.

## Compilation
To compile the project, it is necessary to have g++ installed and compile using the following command line in the terminal:

```
g++ Data.cpp Reader.cpp University.cpp -o University
./University
```

## Operation
The code is divided into two main classes: Reader and Data, contained in the files ```Reader.h``` and ```Data.h```, respectively.

### Reader Class 
- Responsible for reading the data from the text file provided by the user.
- The ```UniversityData()``` method processes the data from the file and stores it in a vector of Data objects.
  
### Main 
- The processed data is then used to build a matrix that represents the system of equations to be solved.
- The matrix is passed to the ```gaussianElimination()``` function to calculate the solutions.
- Finally, the code prints the total number of graduated students, the total number of students at the university, and the total number of students at the university, including graduates.

### gaussianElimination() function: 
- Implements the Gauss elimination algorithm to solve systems of linear equations.
- This function is used to solve the matrix generated based on the data from the file.
