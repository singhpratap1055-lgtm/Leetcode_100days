

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // Start from second row and second column
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            
            // Compare current element with top-left element
            if (matrix[i][j] != matrix[i - 1][j - 1]) {
                return false;
            }
        }
    }
    
    return true;
}
