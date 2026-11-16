#ifndef FUNC
#define FUNC

#include <stdio.h>

void printMatrix(int width, int height, int (*arr)[]);
int readValue(FILE *file, int *value);
int minInArr(int *mas, int length, int *visited);
void printRoute(int *route, int length);
int calculateWeight(int (*matrix)[], int *route, int length);

#endif