#define N 100
#include <stdio.h>
#include <ctype.h>

void printMatrix(int width, int height, int (*arr)[N]) {
    printf("\n      ");

    for (int j = 0; j < width; j++) {
        printf("%4d", j + 1);
    }

    printf("\n      ");

    for (int j = 0; j < width; j++) {
        printf("----");
    }

    printf("\n");

    for (int i = 0; i < height; i++) {
        printf("%4d |", i + 1);

        for (int j = 0; j < width; j++) {
            printf("%4d", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int readValue(FILE *file, int *value) {
    if (fscanf(file, "%d", value) != 1) {
        return 0;
    }

    int ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ',' || isspace((unsigned char)ch)) {
            continue;
        }

        ungetc(ch, file);
        break;
    }

    return 1;
}

int minInArr(int *mas, int length, int *visited) {
    int minIndex = -1;
    int minElement = N;

    for (int i = 0; i < length; i++) {
        if (mas[i] == 0) continue;
        if (visited[i]) continue;

        if (mas[i] < minElement) {
            minIndex = i;
            minElement = mas[i];
        }
    }

    return minIndex;
}

void printRoute(int *route, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", route[i]);

        if (i < length - 1) {
            printf(" -> ");
        }
    }

    printf("\n");
}

int calculateWeight(int (*matrix)[N], int *route, int length) {
    int totalWeight = 0;

    for (int i = 0; i < length - 1; i++) {
        totalWeight += matrix[route[i] - 1][route[i + 1] - 1];
    }

    return totalWeight;
}