#include <iostream>
#include "../../I-O_Abin/I_O_Abin.hpp"
#include "../../Ejercicios_avanzados_Abin/Ejercicios_avanzados_Abin.hpp"

using namespace std;

typedef char T_elem;
const T_elem fin='#';

int main() {

    Abin<T_elem> R;
    /********************************************************Leer Arbol binario en abin_renegades.dat******************************************/

    ifstream file_input("..\\..\\I-O_Abin\\abin_renegades.dat");
    try {
        rellenarAbin(file_input,R);
    }catch (Abin<T_elem>::Error e){
        cout<<e.why();
    }

    cout <<"Caracteristicas del Arbol Renegado*************************************:\n"<<endl;
    imprimirAbin(R);

    cout <<"\n\nRenegados ?:"<< renegades(R) << endl;

   return 0;
}
