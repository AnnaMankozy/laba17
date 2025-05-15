#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS1 10
#define COLS1 10
#define ROWS2 15
#define COLS2 20

void count_negatives(int *matrix, int rows, int cols, int *result) {
    for (int j = 0; j < cols; j+=1) {
        result[j] = 0;
        for (int i = 0; i < rows; i+=1) {
            int value = *(matrix + i * cols + j);  
            if (value < 0)
                result[j]+=1;
        }
    }
}

void fill_matrix(int *matrix, int rows, int cols, int min, int max) {
    for (int i = 0; i < rows * cols; i+=1) {
        matrix[i] = min + rand() % (max - min + 1);
    }
}

void print_matrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i+=1){
        for (int j = 0; j < cols; j+=1) {
            printf("%4d ", *(matrix + i * cols + j));
        }
        printf("\n");
    }
}

void print_counts(int *counts, int size) {
    for (int i = 0; i < size; i+=1) {
        printf("Стовпець %2d: %d від’ємн.\n", i + 1, counts[i]);
    }
}

int main() {
    system("chcp 65001");
    srand(time(NULL));

    int a[ROWS1][COLS1];
    int b[ROWS2][COLS2];
    int countA[COLS1];
    int countB[COLS2];

    fill_matrix((int *)a, ROWS1, COLS1, -10, 10);
    fill_matrix((int *)b, ROWS2, COLS2, -10, 10);

    printf("Матриця A[10][10]:\n");
    print_matrix((int *)a, ROWS1, COLS1);
    count_negatives((int *)a, ROWS1, COLS1, countA);
    printf("\nКількість від’ємних у кожному стовпчику A:\n");
    print_counts(countA, COLS1);

    printf("\nМатриця B[15][20]:\n");
    print_matrix((int *)b, ROWS2, COLS2);
    count_negatives((int *)b, ROWS2, COLS2, countB);
    printf("\nКількість від’ємних у кожному стовпчику B:\n");
    print_counts(countB, COLS2);

    return 0;
}