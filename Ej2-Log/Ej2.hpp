
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void logMessage(string mensaje, int NivelSeveridad);
void logMessage(string error_men, string Archivo, int Linea);
void logMessage(string mensaje_de_acceso, string username);
bool error_test(void);
string create_output(string mensaje, int NivelSeveridad);