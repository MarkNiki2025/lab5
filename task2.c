#include <stdio.h>
#define N 100

void printMatrix(int width, int height, int (*arr)[N]) {
    printf("\n");
    printf("      ");
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

int main() {
    int matrix[N][N] = {0};
    int length = 0;
    int choice = 0;
    printf("Do you wanna use default values or print by yourself? \n");
    printf("1 - default \n");
    printf("2 - custom values \n");
    printf("Your choice: ");

    if (!scanf("%d", &choice) || choice < 0 || choice > 2) {
        printf("Incorrect option");
        return 1;
    }

    if (choice == 1) {
        length = 8;
        int j =0;

        FILE *file = fopen("task2.txt", "r");

        if (file == NULL) {
            perror("File opening error");
            return 1;
        }

        for (int i = 0; i < length; i++) {
            for ( j = 0; j < length; j++){
                if (fscanf(file, "%d, ", &matrix[i][j]) != 1) {
                    printf("File reading error");
                    return 1;
                }
            }
        }
        fclose(file);
    }
    if (choice == 2) {
        printf("Pls write how many points you have :)\n");
        printf("Num of points: ");

        if(!scanf("%d",&length) || length > N || length < 0) {
            printf("It is not coorect option");
            return 1;
        }

        printf("\n");
        printf("Now pls write how weigths for our matrix))\n");

        for(int i = 0; i < length; i++){
            for(int j = 0; j < length; j++) {
                printf("Write %d.%d: ",i + 1,j + 1);
                if(!scanf("%d",&matrix[i][j]) || matrix[i][j] > N - 1 || matrix[i][j] < 0 || matrix[i][i] < 0) {
                    printf("It is not coorect option");
                    return 1;
                }
            }
        }
        printf("\n");
    }

    printMatrix(length,length, &matrix[0]);
    int copyMatrix[N][N];
    for(int i = 0; i < length; i ++) {
        for (int j = 0; j < length; j++){
            *(*(copyMatrix + i) + j) = *(*(matrix + i) + j);
        }
    }

    int route[N];       // тут буде гам шлях
    int visited[N] = {0}; // тут відвідані вже вершинки
    int numOfVisited = 1;
    int i = 0;
    route[0] = 1;
    visited[0] = 1;

    while (numOfVisited < length) {
        int minIndex = minInArr(copyMatrix[i], length, visited);

        if (minIndex == -1) {
            printf("Hamiltonian cycle not found\n");
            return 1;
        }

        i = minIndex;
        visited[i] = 1;
        route[numOfVisited] = i + 1;
        numOfVisited++;
    }

    printf ("\n");

    printf("Your gam Route: \n");

    for(int i = 0; i < length - 1; i++){
        printf("%d -> ", route[i]);
    }

    printf ("%d", route[length - 1]);
    printf(" Length: %d",length);

    if (matrix[i][0] == 0) {
        printf("Hamiltonian cycle not found\n");
        return 1;
    }

    route[length] = 1;
    printf("\n");
    printf("Your gam Cycle: \n");

    for(int i = 0; i < length; i++){
        printf("%d -> ", route[i]);
    }


    printf ("%d", route[length]);
    printf(" Length: %d",length + 1);
    
    return 0;
}