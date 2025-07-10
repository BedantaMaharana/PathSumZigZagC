#include <stdlib.h>   //malloc(), free() for dynamic memory allocation
#include <stdio.h>    //printf(), scanf() for input/output operations
#include <stdbool.h>  //for using bool type and true/false values
bool check_prime(int num) { //Function for checking Prime number
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2)
        if (num % i == 0) return false;
    return true;
}
int compute_zigzag_sum(int** matrix, int n) { // function that computes the zigzag diagonal sum
    int sum = 0;
    for (int diag = 0; diag < 2 * n - 1; diag++) {
        if (diag % 2 == 0) { //for diagonally upward  movement
            int row = (diag < n) ? diag : n - 1;
            int col = diag - row;
            while (row >= 0 && col < n) {
                int val = matrix[row][col];
                sum += (check_prime(val) ? -val : val);
                row--;
                col++;
            }
        } else { //for diagonally downward movement
            int col = (diag < n) ? diag : n - 1;
            int row = diag - col;
            while (col >= 0 && row < n) {
                int val = matrix[row][col];
                sum += (check_prime(val) ? -val : val);
                row++;
                col--;
            }
        }
    } return sum; //returns the sum
}
int main() {
    int n;
    printf("Enter the number of rows or columns (n): "); //User input for number of elements
    scanf("%d", &n);
    int** matrix = (int**)malloc(n * sizeof(int*));    // Allocate memory to the matrix
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the %d elements of the matrix:\n", n * n); //User input for elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int result = compute_zigzag_sum(matrix, n); //calling the compute_zigzag_sum() function
    printf("Output: %d\n", result); //prints sum
    for (int i = 0; i < n; i++) free(matrix[i]);     // Free memory
    free(matrix);
    return 0;
}
