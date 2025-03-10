#include <iostream>
using namespace std;

bool compare_texts(const char* Atext,const char* Btext, unsigned pos);



int main (void){
    const char* text1 = "Hola prueba!";
    const char* text2 = "Hola prueba!";
    const char* text3 = "Soy distinto!!!";

    const char * long_text = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";
    const char * long_text_copy = "know that, because my heart tells me I am right, for I cannot hurt you in any way, I cannot wound you";

    if (compare_texts(text1, text2, 0)) {
        cout << "text1 y text2 iguales." << endl;
    } else {
        cout << "text1 y text2 distintos." << endl;
    }

    if (compare_texts(text1, text3, 0)) {
        cout << "text1 y text3 iguales." << endl;
    } else {
        cout << "text1 y text3 distintos." << endl;
    }
 
    if (compare_texts(long_text,long_text_copy , 0)) {
        cout << "long_text y long_text_copy iguales." << endl;
    } else {
        cout << "long_text y long_text_copy distintos." << endl;
    }


    return 0;
}
bool compare_texts(const char* Atext,const char* Btext, unsigned pos ){

    if (Atext[pos] != Btext[pos]){
        //cout << Atext[pos] << "!=" << Btext[pos] << endl;
        return false;
    }

    if (Atext[pos] == '\0' && Btext[pos] == '\0'){
        return true;
    }

    else {
        return (compare_texts(Atext, Btext, pos+1));
    }
}
