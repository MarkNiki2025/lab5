#ifndef FUNC
#define FUNC
#define N 100
#include <stdio.h>

void printMatrix(int width, int height, int (*arr)[]);
int readValue(FILE *file, int *value);
int minInArr(int *mas, int length, int *visited);
void printRoute(int *route, int length);
int calculateWeight(int (*matrix)[], int *route, int length);
void multiplicationMatrix (int (*matrix)[], int length, int (*multiplicetedCopy)[],int power);
void addMatrices(int length, int count,int matrices[][N][N],int answer[][N]);
void copyMatrix (int (*matrix1)[], int (*matrix2)[], int length);
void multiplicationMatrix(int (*matrix)[], int length, int (*multiplicetedCopy)[], int power);
void vorshel (int (*matrix)[N],int (*matrixAnswer)[N], int length);

#endif