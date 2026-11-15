#include <stdio.h>
#define N 100

void printMatrix(int width, int height,int (*arr)[N]){

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++) {
            printf("%d ", *(*(arr + i) +j));
        }
        printf("\n");
    }
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
        length = 5;
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
                if(!scanf("%d",&matrix[i][j]) || matrix[i][j] > N - 1 || matrix[i][j] < 0) {
                    printf("It is not coorect option");
                    return 1;
                }
            }
        }
        printf("\n");
    }

    printMatrix(length,length, &matrix[0]);

    int route[N];       
    int visited[N] = {0};

    for(int i = 0; i < )
    return 0;
}