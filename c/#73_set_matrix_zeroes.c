#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    /* Check if the matrix is empty */
    if (0 == matrixSize || 0 == *matrixColSize) {
        return;
    }

    int rows = matrixSize;
    int cols = *matrixColSize;

    /* Variables to check if the first row and first column contain zeros */
    int firstRowZero = 0;
    int firstColZero = 0;

    /* Check if the first row contains zero */
    for (int i = 0; i < cols; ++i) {
        if (0 == matrix[0][i]) {
            firstRowZero = 1;
            break;
        }
    }

    /* Check if the first column contains zero */
    for (int i = 0; i < rows; ++i) {
        if (0 == matrix[i][0]) {
            firstColZero = 1;
            break;
        }
    }

    /* Use the first row and first column as flags to mark rows and columns to 
    be zeroed */
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (0 == matrix[i][j]) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    /* Set zeros based on the flags in the first row and first column */
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (0 == matrix[i][0] || 0 == matrix[0][j]) {
                matrix[i][j] = 0;
            }
        }
    }

    /* Set zeros in the first row if necessary */
    if (firstRowZero) {
        for (int i = 0; i < cols; ++i) {
            matrix[0][i] = 0;
        }
    }

    /* Set zeros in the first column if necessary */
    if (firstColZero) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
}

/* Function to print the matrix */
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrixSize = 3;
    int matrixColSize = 3;

    /* Example matrix */
    int matrix[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

    /* Convert the matrix to a dynamic array to use in the function */
    int** dynamicMatrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; ++i) {
        dynamicMatrix[i] = (int*)malloc(matrixColSize * sizeof(int));
        for (int j = 0; j < matrixColSize; ++j) {
            dynamicMatrix[i][j] = matrix[i][j];
        }
    }


    /* Print the original matrix */
    printf("Original Matrix:\n");
    printMatrix(dynamicMatrix, matrixSize, matrixColSize);

    /* Call the setZeroes function */
    setZeroes(dynamicMatrix, matrixSize, &matrixColSize);

    /* Print the modified matrix */
    printf("\nMatrix after setting zeroes:\n");
    printMatrix(dynamicMatrix, matrixSize, matrixColSize);

    /* Free the dynamically allocated memory */
    for (int i = 0; i < matrixSize; ++i) {
        free(dynamicMatrix[i]);
    }
    free(dynamicMatrix);

    return 0;
}