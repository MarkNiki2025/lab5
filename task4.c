
#include <stdio.h>
#include "functions.h"

#define N 100

int main() {
    int matrix[N][N] = {0};
    int multiplicetedCopy[N][N] = {0};
    int answer[N][N] = {0};

    // Масив усіх степенів матриці
    static int matrices[N][N][N] = {0};

    int length = 0;
    int choice = 0;

    printf("Do you wanna use default values or print by yourself?\n");
    printf("1 - default\n");
    printf("2 - custom values\n");
    printf("Your choice: ");

    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Incorrect option\n");
        return 1;
    }

    if (choice == 1) {
        length = 6;

        FILE *file = fopen("task4.txt", "r");

        if (file == NULL) {
            perror("File opening error");
            return 1;
        }

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {

                if (!readValue(file, &matrix[i][j])) {
                    printf("File reading error\n");
                    fclose(file);
                    return 1;
                }

                if (matrix[i][j] < 0 || matrix[i][j] > 1) {
                    printf("Invalid matrix value\n");
                    fclose(file);
                    return 1;
                }
            }
        }

        fclose(file);
    }

    if (choice == 2) {
        printf("How many vertices do you have?\n");
        printf("Number of vertices: ");

        if (scanf("%d", &length) != 1 || length < 1 || length > N) {
            printf("Incorrect number of vertices\n");
            return 1;
        }

        printf("\nEnter matrix (0 or 1):\n");

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {

                printf("Write %d.%d: ", i + 1, j + 1);

                if (scanf("%d", &matrix[i][j]) != 1 ||
                    matrix[i][j] < 0 ||
                    matrix[i][j] > 1) {

                    printf("Incorrect num\n");
                    return 1;
                }
            }
        }
    }

    printf("\n\tYour matrix");
    printMatrix(length, length, matrix);

    // Зберігаємо A^1
    copyMatrix(matrix, matrices[0], length);

    // Обчислюємо та зберігаємо наступні степені
    for (int i = 2; i <= length; i++) {

        multiplicationMatrix(matrix, length, multiplicetedCopy, i);

        copyMatrix(multiplicetedCopy, matrices[i - 1], length);

        printf("\nYour matrix in %d power\n", i);
        printMatrix(length, length, multiplicetedCopy);
    }

    // Об'єднуємо всі степені через OR
    addMatrices(length, length, matrices, answer);

    printf("\nYour reachability matrix by powering\n");
    printMatrix(length, length, answer);

    vorshel(matrix,answer,length);
    printf("\n");
    printf("\nYour reachability matrix by algorithm\n");
    printMatrix(length, length, answer);


    return 0;
}
