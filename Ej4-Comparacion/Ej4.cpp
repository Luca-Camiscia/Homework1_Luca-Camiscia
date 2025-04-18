#include "Ej4.hpp"
constexpr bool Pre_compare_texts1(const char* Atext,const char* Btext, unsigned pos ){

    if (Atext[pos] != Btext[pos]){
        //cout << Atext[pos] << "!=" << Btext[pos] << endl;
        return false;
    }

    if (Atext[pos] == '\0' && Btext[pos] == '\0'){
        return true;
    }

    else {
        return (Pre_compare_texts1(Atext, Btext, pos+1));
    }
}

int main (int argc, char*argv[]){
    int resA, resB, i;
    int tries;
    //inicializo las variables
    chrono::high_resolution_clock::time_point startTime, endTime;
    chrono::nanoseconds elapsedTime;
    //Preprocesamiento
    
    startTime = chrono::high_resolution_clock::now();
    constexpr const char* pre_A = "hello";
    constexpr const char* pre_B = "hello";
    constexpr bool result = Pre_compare_texts1(pre_A, pre_B, 0);
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
    int res_Pre = static_cast<int>(elapsedTime.count());
    //---------------------------------------------------------------
    
    if (argc == 2){
        tries = atoi(argv[1]);
    }
    else{ 
     tries = 100; //default
    }
    int A_data[tries];
    int B_data[tries];
    //func1 
    for (i = 0;i<tries;i++) { 
    startTime = chrono::high_resolution_clock::now();
    if (!testfunc(compare_texts1)){
        cout << "La funcion no funciona correctamente" << endl;
        return 0;
    }
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
    A_data[i] = static_cast<int>(elapsedTime.count()); 
    }
    resA = avg(A_data, tries);

    //func2
    for (i = 0;i<tries;i++) { 
    startTime = chrono::high_resolution_clock::now();
    if (!testfunc2(compare_texts2)){
        cout << "La funcion no funciona correctamente" << endl;
        return 0;
    }
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<std::chrono::nanoseconds>( endTime - startTime);
    B_data[i] = static_cast<int>(elapsedTime.count());
    }
    resB = avg(B_data, tries);


    cout << "Analisis tiempo de ejecucion\n---------------------------------------------" << endl; 
    if (resA < resB){
        cout << "Es mas efectivo el char * !" << endl;
    }
    else{
        cout << "Es mas efectivo el string !" << endl;
    }

    cout << "Espacio muestral -> " << tries << endl;
    cout <<"Char* avg-> " << resA << " nanosegundos" <<endl;
    cout <<"String avg ->" << resB << " nanosegundos" <<endl;
    cout << "----------------------------------------------------" << endl;
    cout << "El tiempo que tardo con preprocesamiento la funcion de char* es -> " << res_Pre << endl;
    return 0;
}

int avg(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }
    return sum / size;
}
    
bool compare_texts1(const char* Atext,const char* Btext, unsigned pos ){

    if (Atext[pos] != Btext[pos]){
        //cout << Atext[pos] << "!=" << Btext[pos] << endl;
        return false;
    }

    if (Atext[pos] == '\0' && Btext[pos] == '\0'){
        return true;
    }

    else {
        return (compare_texts1(Atext, Btext, pos+1));
    }
}


bool compare_texts2(string Atext,string Btext, unsigned pos ){

    if (Atext[pos] != Btext[pos]){
        //cout << Atext[pos] << "!=" << Btext[pos] << endl;
        return false;
    }

    if (pos == (Atext.size()-1) && pos == (Btext.size()-1)) { //compruebo si esoty en la ultima pos de ambos
        return true;
    }
    else {
        return (compare_texts2(Atext, Btext, pos+1));
    }
    }

bool testfunc(bool (*compare_func)(const char*, const char*, unsigned)) {
    const char* text1 = "Hola prueba!";
    const char* text2 = "Hola prueba!";
    const char* text3 = "Soy distinto!!!";

    const char * long_text = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";
    const char * long_text_copy = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";

    if (compare_func(text1, text2, 0)) {
        //cout << "text1 y text2 iguales." << endl;
        // Esperado
    } else {
        //cout << "text1 y text2 distintos." << endl;
        //Error
        return false;
    }

    if (compare_func(text1, text3, 0)) {
        //cout << "text1 y text3 iguales." << endl;
        //error
        return false;
    } else {
        //cout << "text1 y text3 distintos." << endl;
        //esperado
    }
 
    if (compare_func(long_text,long_text_copy , 0)) {
        //cout << "long_text y long_text_copy iguales." << endl;
        //esperado
    } else {
        //cout << "long_text y long_text_copy distintos." << endl;
        return false;
    }

    return true;
    }


bool testfunc2(bool (*compare_func)(string, string, unsigned)) {
    string text1 = "Hola prueba!";
    string text2 = "Hola prueba!";
    string text3 = "Soy distinto!!!";

    string long_text = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";
    string long_text_copy = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";

    if (compare_func(text1, text2, 0)) {
        //cout << "text1 y text2 iguales." << endl;
        // Esperado
    } else {
        //cout << "text1 y text2 distintos." << endl;
        //Error
        return false;
    }

    if (compare_func(text1, text3, 0)) {
        //cout << "text1 y text3 iguales." << endl;
        //error
        return false;
    } else {
        //cout << "text1 y text3 distintos." << endl;
        //esperado
    }
 
    if (compare_func(long_text,long_text_copy , 0)) {
        //cout << "long_text y long_text_copy iguales." << endl;
        //esperado
    } else {
        //cout << "long_text y long_text_copy distintos." << endl;
        return false;
    }

    return true;

}



