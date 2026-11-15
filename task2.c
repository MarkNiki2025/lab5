
#include <stdio.h>
#include <ctype.h>

#define N 100

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

int main() {
    int matrix[N][N] = {0};
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
        length = 8;

        FILE *file = fopen("task2.txt", "r");

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

                if (matrix[i][j] < 0 || matrix[i][j] >= N) {
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

        printf("\nEnter matrix weights (0 means no edge):\n");

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                printf("Write %d.%d: ", i + 1, j + 1);

                if (scanf("%d", &matrix[i][j]) != 1 ||
                    matrix[i][j] < 0 ||
                    matrix[i][j] >= N) {

                    printf("Incorrect weight\n");
                    return 1;
                }
            }
        }
    }

    printf("\nInitial weight matrix:\n");
    printMatrix(length, length, matrix);

    int route[N + 1];
    int visited[N] = {0};

    int numOfVisited = 1;
    int i = 0;

    route[0] = 1;
    visited[0] = 1;

    while (numOfVisited < length) {

        int minIndex = minInArr(matrix[i], length, visited);

        if (minIndex == -1) {
            printf("Hamiltonian cycle not found.\n");
            printf("Greedy algorithm reached a dead end.\n");

            printf("Current route: ");
            printRoute(route, numOfVisited);

            return 1;
        }

        i = minIndex;

        visited[i] = 1;
        route[numOfVisited] = i + 1;

        numOfVisited++;
    }

    printf("\nHamiltonian path:\n");
    printRoute(route, length);

    int pathWeight = calculateWeight(matrix, route, length);

    printf("Path weight: %d\n", pathWeight);
    printf("Path length: %d\n", length);

    if (matrix[i][0] == 0) {
        printf("\nHamiltonian cycle not found.\n");
        printf("There is no edge from vertex %d to vertex 1.\n", i + 1);

        return 1;
    }

    route[length] = 1;

    printf("\nHamiltonian cycle:\n");
    printRoute(route, length + 1);

    int cycleWeight = calculateWeight(matrix, route, length + 1);

    printf("Cycle weight: %d\n", cycleWeight); 
    printf("Cycle length: %d\n", length + 1);

    return 0;
}
