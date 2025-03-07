#include <iostream>
using namespace std;

int** matrix_create(int n);
void matrix_fill(int n, int**mtx);
void matrix_print(int ** mtx, int n);

int main(void){
    int size = 5;
    int ** mymtx = matrix_create(size);
    matrix_print(mymtx, size);

}
void matrix_fill(int n, int** mtx) {
    int x = 0;
    int y = 0;
    for (int i = 1; i <= (n * n); i++) {
        mtx[y][x] = i;
        x++;
        if (x >= n) {  // se me lleno la fila
            y++;
            x = 0;
        }
    }

}
int** matrix_create(int n) {
    int** mtx = new int*[n];
    for (int i = 0; i < n; i++) {
        mtx[i] = new int[n];
    }
    matrix_fill (n, mtx);
    return mtx;
}
void matrix_print(int **mtx, int n){
    int x = (n-1);
    int y = (n-1);
    for (int i = 0;i<(n*n); i++){
        cout << "[" << y << "]" << "[" << x << "]" << "==" << mtx[y][x] <<endl;
        x --;
        if (x < 0){ //termine la fila
            x = (n-1);
            y --;
        }
    }
}