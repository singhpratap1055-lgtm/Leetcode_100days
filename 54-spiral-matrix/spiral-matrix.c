

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int total = rows * cols;
    int* result = (int*)malloc(sizeof(int) * total);
    
    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    int k = 0;
    
    while (top <= bottom && left <= right) {
        
        // Traverse left → right
        for (int j = left; j <= right; j++)
            result[k++] = matrix[top][j];
        top++;
        
        // Traverse top → bottom
        for (int i = top; i <= bottom; i++)
            result[k++] = matrix[i][right];
        right--;
        
        // Traverse right → left
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                result[k++] = matrix[bottom][j];
            bottom--;
        }
        
        // Traverse bottom → top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[k++] = matrix[i][left];
            left++;
        }
    }
    
    *returnSize = total;
    return result;
}
