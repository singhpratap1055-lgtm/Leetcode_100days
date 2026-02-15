void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    int i, j;
    
    int firstRowZero = 0;
    int firstColZero = 0;

    // Check if first row has any zero
    for (j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // Check if first column has any zero
    for (i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // Use first row and first column as markers
    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set matrix elements to zero based on markers
    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out first row if needed
    if (firstRowZero) {
        for (j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero out first column if needed
    if (firstColZero) {
        for (i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
