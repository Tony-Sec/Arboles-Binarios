#include <iostream>
#include "../E_S_Abin.hpp"
#include "Ejercicios_basicos_Abin.hpp"

using namespace std;

typedef char T_elem;
const T_elem fin='#';

int main() {
    Abin<T_elem> A,B;

    /********************************************************Leer Arbol binario en abin.dat******************************************/
    cout <<"abin.dat --> Extraer A_bin"<<endl;


    ifstream file_input("..\\I-O_Abin\\abin.dat");
    try {
        rellenarAbin(file_input,A);
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }
    file_input.close();

    cout <<"Caracteristicas del Arbol Binario A************************************:\n"<<endl;
    imprimirAbin(A);

    cout <<"\n\nNumero de Nodos: "<< numero_nodos_abin(A) << endl;
    cout <<"Altura: "<< altura(A) << endl;
    cout <<"Profundidad del nodo "<< A.elemento(A.hijoDrchoB(A.hijoIzqdoB(A.raizB())))<<" :"<<prof_nodo(A,A.hijoDrchoB(A.hijoIzqdoB(A.raizB()))) <<endl;
    cout <<"Desequilibrio: "<< desequilibrio(A) <<endl;
    cout <<"El nodo "<< A.elemento(A.hijoDrchoB(A.hijoIzqdoB(A.raizB())))<<" es hoja? "<<(is_sheet(A,A.hijoDrchoB(A.hijoIzqdoB(A.raizB())))? "SI":"NO")<<endl;
    cout <<"Es pseudocompleto? "<< (pseudocompleto(A)? "SI":"NO") <<endl<<endl<<endl;


    /********************************************************Leer Arbol binario en abin2.dat******************************************/

    ifstream file_input2("..\\I-O_Abin\\abin2.dat");
    try {
        rellenarAbin(file_input2,B);
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }
    file_input2.close();

    cout <<"Caracteristicas del Arbol Binario B************************************:\n"<<endl;
    imprimirAbin(B);

    cout <<"\n\nNumero de Nodos: "<< numero_nodos_abin(B) << endl;
    cout <<"Altura: "<< altura(B) << endl;
    cout <<"Profundidad del nodo "<< B.elemento(B.hijoDrchoB(B.hijoIzqdoB(B.raizB())))<<" :"<<prof_nodo(B,B.hijoDrchoB(B.hijoIzqdoB(B.raizB()))) <<endl;
    cout <<"Desequilibrio: "<< desequilibrio(B) <<endl;
    cout <<"El nodo "<< B.elemento(B.hijoDrchoB(B.hijoIzqdoB(B.raizB())))<<" es hoja? "<<(is_sheet(B,B.hijoDrchoB(B.hijoIzqdoB(B.raizB())))? "SI":"NO")<<endl;
    cout <<"Es pseudocompleto? "<< (pseudocompleto(B)? "SI":"NO") <<endl;
    
    return 0;
}
