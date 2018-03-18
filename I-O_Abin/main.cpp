#include <iostream>
#include "../I_O_Abin.hpp"

using namespace std;

typedef char T_elem;
const T_elem fin = '#';

int main() {

    Abin<T_elem> A (20), B(20);
/********************************************************Guardar Arbol binario en abin.dat***************************************/
    cout << "Introducir A_bin --> abin.dat" << endl;
    try {
        rellenarAbin(A,fin);            //std::cin
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }
    ofstream file_out("abin.dat");
    imprimirAbin(file_out,A,fin);
    file_out.close();
    cout << "\n*** A_bin guardado en abin.dat ***"<<endl;
    
/********************************************************Leer Arbol binario en abin.dat******************************************/
    cout <<"abin.dat --> Extraer A_bin"<<endl;
    ifstream file_input("abin.dat");
    try {
        rellenarAbin(file_input,B);     //std::cout
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }
    file_input.close();


    cout<<"Mostrando A_bin"<<endl;
    imprimirAbin(B);

    return 0;
}
