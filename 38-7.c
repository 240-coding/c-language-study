#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int n, i, j;
    int **m;
 
    scanf("%d", &n);
 
    m = malloc(sizeof(int *) * n);
 
    for (i = 0; i < n; i++)
        m[i] = malloc(sizeof(int) * n);
 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (i == j)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }
 
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < n; i++)
        free(m[i]);
 
    free(m);
}
