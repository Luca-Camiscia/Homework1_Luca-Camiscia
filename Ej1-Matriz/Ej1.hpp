#include <iostream>
#include <limits>
using namespace std;

int** matrix_create(int n);
void matrix_fill(int n, int** mtx);
void matrix_print(int** mtx, int n);
void matrix_destroy(int** mtx, int n);
