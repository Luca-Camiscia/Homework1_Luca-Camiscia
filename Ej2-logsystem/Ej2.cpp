#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void logMessage(string mensaje, int NivelSeveridad);
void logMessage(string error_men, string Archivo, int Linea);
string create_output(string mensaje, int NivelSeveridad);



int main (int argc, char** argv){



logMessage("Debugeo el codigo", 1);
logMessage("Posible mejora en linea x", 2);
logMessage("Posible Leak", 3);
logMessage("Error de memoria", 4);
logMessage("Va a explotar todoooo", 5);

logMessage("Segmentation Fault", "Ejecutable.exe", 32);


}


string create_output(string mensaje, int NivelSeverdiad){

    string messageType;
    switch (NivelSeverdiad)
    {
    case 1:
        messageType = "[DEBUG]";
        break;
    

    case 2:
        messageType = "[INFO]";
        break;
    case 3:
        messageType = "[WARNING]";
        break;
    case 4:
        messageType = "[ERROR]";
        break;
    case 5 :
        messageType = "[CRITICAL]";
        break;
    default:
        messageType = "[UNKNOWN]";
        break;
    }

    return messageType + " " + mensaje + "\n";


}

void logMessage(string mensaje, int NivelSeveridad){
    ofstream outFile ("Logsystem.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;

        cout << "El archivo no existe. Creándolo..." << endl;
        
        // Crear el archivo
        ofstream outFile("Logsystem.txt");
        if (!outFile) {
            cout << "Error al crear el archivo." << endl;
            return;
        }
    }
    string new_log = create_output(mensaje, NivelSeveridad);
    outFile << new_log;
    outFile.close();
    return;

}

void logMessage(string error_men, string Archivo, int Linea){

    string combinedMessage = error_men + " -> " + Archivo + "-> linea -> " + to_string(Linea) + "\n";
    logMessage(combinedMessage, 4);
    return;
}