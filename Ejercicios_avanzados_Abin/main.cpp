#include <iostream>
#include "../I-O_Abin/I_O_Abin.hpp"
#include "Ejercicios_avanzados_Abin.hpp"

using namespace std;

typedef char T_elem;
const T_elem fin='#';

int main() {

    Abin<T_elem> A,B,C,R;

//    /********************************************************Leer Arbol binario en abin.dat******************************************/
//    cout <<"abin.dat --> Extraer A_bin"<<endl;
//
//
//    ifstream file_input("..\\..\\I-O_Abin\\cmake-build-debug\\abin.dat");
//    try {
//        rellenarAbin(file_input,A);
//    }catch (Abin<T_elem>::Error e){
//        cout<<e.why();
//    }
//    file_input.close();
//    /********************************************************Leer Arbol binario en abin2.dat******************************************/
//
//    ifstream file_input2("..\\..\\I-O_Abin\\cmake-build-debug\\abin2.dat");
//    try {
//        rellenarAbin(file_input2,B);
//    }catch (Abin<T_elem>::Error e){
//        cout<<e.why();
//    }
//    file_input2.close();

    /********************************************************Leer Arbol binario en abin_renegades.dat******************************************/

    ifstream file_input3("..\\..\\I-O_Abin\\cmake-build-debug\\abin_renegades.dat");
    try {
        rellenarAbin(file_input3,R);
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }
    file_input3.close();

//    cout <<"Caracteristicas del Arbol Binario A************************************:\n"<<endl;
//    imprimirAbin(A);
//
//    cout <<"Caracteristicas del Arbol Binario B************************************:\n"<<endl;
//    imprimirAbin(B);
//
//    cout <<"\n\nSon Similares A y B ?:"<< (similares(A,B)? "SI":"NO") << endl;
//    C=reflejado(A);
//    cout <<"\n\nArbol reflejado B ?:"<< endl;
//    try {
//        imprimirAbin(C);
//    }catch (Abin<T_elem>::Error e){
//        cout<<e.why();
//    }


    cout <<"Caracteristicas del Arbol Renegado*************************************:\n"<<endl;
    imprimirAbin(R);

    cout <<"\n\nRenegados ?:"<< renegades(R) << endl;



   return 0;
}