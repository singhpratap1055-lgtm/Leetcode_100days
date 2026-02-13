

int** transpose(int** matrix, int matrixSize, int* matrixColSize, 
                int* returnSize, int** returnColumnSizes) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    // Transposed matrix will have size: cols x rows
    *returnSize = cols;
    
    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(sizeof(int) * cols);
    
    // Allocate memory for result matrix
    int** result = (int**)malloc(sizeof(int*) * cols);
    
    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(sizeof(int) * rows);
        (*returnColumnSizes)[i] = rows;
    }
    
    // Fill transpose
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}
