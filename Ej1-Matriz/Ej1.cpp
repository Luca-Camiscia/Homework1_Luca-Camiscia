#include <iostream>
using namespace std;

int** matrix_create(int n);
void matrix_fill(int n, int**mtx);
void matrix_print(int ** mtx, int n);
void matrix_destroy(int ** mtx, int n);

int main(void){
    int size;
    cout << "Ingrese la dimension de la matriz " <<endl;
    cin >> size;
    int ** mymtx = matrix_create(size);
    if (mymtx == NULL){ 
        cout << "Algo salio mal :( " << endl;
        return 1;
        }
    matrix_print(mymtx, size);
    matrix_destroy(mymtx, size);
    return 0;
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
    int** mtx = new (nothrow) int*[n];
    if (mtx == nullptr) {
        cerr << "Error: No se pudo alocar memoria para las filas de la matriz." << endl;
        return NULL;
    }
         
    for (int i = 0; i < n; i++) {
        mtx[i] = new (nothrow) int[n];
        if (mtx[i] == nullptr) {
            cerr << "Error: No se pudo alocar memoria para las columnas de la matriz." << endl;
            return NULL;
        }
    }

    matrix_fill(n, mtx);
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

void matrix_destroy(int **mtx, int n){
    for (int i = 0; i < n; i++) {
        delete[] mtx[i];
    }
    delete[] mtx;
}