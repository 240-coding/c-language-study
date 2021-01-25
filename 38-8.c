#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
 
 
int main(){
    int row, col;
    int i, j;
    int a, b;
    char **matrix;
 
    scanf("%d %d", &row, &col);
 
    matrix = malloc(sizeof(char *) * row);
 
    for (i = 0; i < row; i++)
        matrix[i] = malloc(sizeof(char) * (col + 1));
 
    for (i = 0; i < row; i++)
        scanf("%s", matrix[i]);
 
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++){
            if (matrix[i][j] != '*'){
                matrix[i][j] = '0';
            }
        }
    }
 
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            if (matrix[i][j] != '*'){
                for (a = i-1; a <= i+1; a++){
                    if (a == -1 || a == row)
                        continue;
                    for (b = j-1; b <= j+1; b++){
                        if (b == -1 || b == col)
                            continue;
                        if (matrix[a][b] == '*')
                            matrix[i][j] += 1;
                    }
                }
            }
        }
    }
 
 
    for (i = 0; i < row; i++){
        printf("%s\n", matrix[i]);
    }
 
    for (i = 0; i < row; i++)
        free(matrix[i]);
 
    free(matrix);
 
    return 0;
}
