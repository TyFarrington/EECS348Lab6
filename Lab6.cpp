#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX_SIZE = 100;

void readMatricesFromFile(int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int& size, const char* filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        exit(1);
    }

    inFile >> size;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> matrixA[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inFile >> matrixB[i][j];
        }
    }

    inFile.close();
}
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(2) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void addMatrices(int result[MAX_SIZE][MAX_SIZE], int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int result[MAX_SIZE][MAX_SIZE], int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

void subtractMatrices(int result[MAX_SIZE][MAX_SIZE], int matrixA[MAX_SIZE][MAX_SIZE], int matrixB[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

void updateElement(int matrix[MAX_SIZE][MAX_SIZE], int size, int row, int col, int newValue) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        matrix[row][col] = newValue;
    } else {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

int findMaxValue(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int maxValue = matrix[0][0];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] > maxValue) {
                maxValue = matrix[i][j];
            }
        }
    }
    return maxValue;
}

void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main() {
    int size;
    int matrixA[MAX_SIZE][MAX_SIZE];
    int matrixB[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    readMatricesFromFile(matrixA, matrixB, size, "matrix_input.txt");

    std::cout << "Your name" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, size);

    addMatrices(result, matrixA, matrixB, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);

    multiplyMatrices(result, matrixA, matrixB, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);

    subtractMatrices(result, matrixB, matrixA, size);
    std:: cout << "Matrix Difference (B - A):" << std::endl;
    printMatrix(result, size);

    int updateRow = 1, updateCol = 1, newValue = 10;
    std::cout << "Updating Matrix A at position [" << updateRow << "][" << updateCol << "] to " << newValue << std::endl;
    updateElement(matrixA, size, updateRow, updateCol, newValue);
    printMatrix(matrixA, size);

    int maxValue = findMaxValue(matrixA, size);
    std::cout << "Max value in Matrix A: " << maxValue << std::endl;

    std::cout << "Transposing Matrix A:" << std::endl;
    transposeMatrix(matrixA, size);
    printMatrix(matrixA, size);

    return 0;
}