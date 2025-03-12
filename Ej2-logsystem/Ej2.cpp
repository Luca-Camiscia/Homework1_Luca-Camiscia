#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void logMessage(string mensaje, int NivelSeveridad);
void logMessage(string error_men, string Archivo, int Linea);
void logMessage(string mensaje_de_acceso, string username);
void error_test(void);
string create_output(string mensaje, int NivelSeveridad);



int main (int argc, char*argv[]) { 

logMessage("Debugeo el codigo", 1);
logMessage("Posible mejora en linea x", 2);
logMessage("Posible Leak", 3);
logMessage("Error de memoria", 4);
logMessage("Va a explotar todoooo", 5);
logMessage("Segmentation Fault", "Ejecutable.exe", 32);
logMessage("ACCESS GRANTED", "Steve Jobs");
if (argc == 2){
    if (atoi(argv[1]) == 1){
        error_test();
    } 
}
cout << "esto no se imprimira ya que se terminara la ejecucion del problama con la funcion anterior" <<endl;
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
    case 6:
        messageType = "[SECURITY]";
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

    string combinedMessage = error_men + " -> " + Archivo + "-> linea -> " + to_string(Linea);
    logMessage(combinedMessage, 4);
    return;
}

void logMessage(string mensaje_de_acceso, string username){

    string Message = username + ": " + mensaje_de_acceso;

    logMessage(Message, 6);

}

void error_test(void){
    try{ 
    throw runtime_error("Un error salvaje ha aparecido!");
    }
    catch (const runtime_error& e) {
        logMessage(e.what(), 4);
        exit(1); 
    }
}