#ifndef RENEGADES_HPP
#define RENEGADES_HPP


#include "../../A_bin_dinamico.hpp"
#include "../../Ejercicios_basicos_Abin/Ejercicios_basicos_Abin.hpp"

template<typename T>
int renegadesrec(Abin<T>& A,typename Abin<T>::nodo n,int& ntrue,int& nfalse) {

    if(n==Abin<T>::NODO_NULO) return min(ntrue,nfalse);
    else {
        if (A.elemento(n)=='1') ntrue++;
        else nfalse++;
    }
    return  max(renegadesrec(A, A.hijoIzqdoB(n), ntrue, nfalse),renegadesrec(A, A.hijoDrchoB(n), ntrue, nfalse));

}

template<typename T>
int renegades(Abin<T>& A){
    int ntrue=0;
    int nfalse=0;
    int renegades=renegadesrec(A,A.raizB(),ntrue,nfalse);
    if(renegades*2==numero_nodos_abin(A)){
        cout<<"Arbol sin renegados!!!"<<endl;
        renegades=0;
    }
    return renegades;
}

#endif //RENEGADES_HPP
