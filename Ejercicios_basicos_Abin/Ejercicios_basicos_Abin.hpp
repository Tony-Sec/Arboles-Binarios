//
// Created by Antonio on 13/03/2018.
//

#ifndef ABIN_EJERCICIOS_BASICOS_HPP
#define ABIN_EJERCICIOS_BASICOS_HPP

/*Incluir la biblioteca que se necesite.Por defecto: A_bin_dinamico.hpp*/

#include "../A_bin_dinamico.hpp"
//#include "../A_bin_vectorial_posiciones_relativas.hpp"
#include <functional>


template <typename T>
bool is_sheet(const Abin<T>& A,typename Abin<T>::nodo n){
    assert(!A.arbolVacioB());
    assert(n!=Abin<T>::NODO_NULO);
    return (A.hijoIzqdoB(n)==Abin<T>::NODO_NULO && A.hijoDrchoB(n)==Abin<T>::NODO_NULO)? true:false;
}


/**********************************************************************************Número de nodos en un Árbol Binario*/

/*template <typename T>
int numero_nodos_abin_rec(const Abin<T>& A,typename Abin<T>::nodo n,int num_nodos) {
    if(n == Abin<T>::NODO_NULO) return 0; //Arbol vacío
    else{
        num_nodos = numero_nodos_abin_rec(A,A.hijoIzqdoB(n),num_nodos) +
                    numero_nodos_abin_rec(A,A.hijoDrchoB(n),num_nodos);
    }
    return 1 + num_nodos;
}


template <typename T>
int numero_nodos_abin(const Abin<T>& A) {
    return numero_nodos_abin_rec(A,A.raizB(),0);
}
*/

//Lambda recursiva
template <typename T>
int numero_nodos_abin(const Abin<T>& A) {

    std::function<int(typename Abin<T>::nodo n,int)>
    func =[&A,&func](typename Abin<T>::nodo n,int num_nodos)-> int {

        if(n == Abin<T>::NODO_NULO ) return 0;//Arbol vacío o fin del nodo
        else{
            num_nodos=1+func(A.hijoIzqdoB(n),num_nodos)+func(A.hijoDrchoB(n),num_nodos);
        }
        return num_nodos ;
    };
    return func(A.raizB(),0);
}

/*******************************************************************************************Altura de un Árbol Binario*/

template<typename T>
int max(int a, int b){
    return a>b? a:b;
}

template <typename T>
int alturarec(Abin<T>& A,typename Abin<T>::nodo n) {
    if(n == Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1+max(alturarec(A,A.hijoIzqdoB(n)),alturarec(A,A.hijoDrchoB(n)));
    }
}

template <typename T>
int altura (Abin<T>& A){
    if(A.raizB()==Abin<T>::NODO_NULO){
        return 0;
    }else
        return alturarec(A, A.raizB());
}

/************************************************************************************************Profundida de un nodo*/

template<typename T>
int prof_nodo(const Abin<T>& A,typename Abin<T>::nodo n){
    if(n==A.raizB()){ //La profundidad del nodo raíz es 0
        return 0;
    }else{
        return 1+prof_nodo(A,A.padreB(n));
    }
}
/*********************************************************************************************Ejercicios  4 Y 5 en hpp*/


/*********************************************************************************************Desequilibrio de un Abin*/

int maxi(int a, int b,int c){
    return ((a>b && a>c)? a:((b>c)? b:c));
}


template <typename T>
int desequilibriorec(Abin<T>& A,typename Abin<T>::nodo n) {
    if(n==Abin<T>::NODO_NULO){
        return 0;

    }else{
        int diff=abs(alturarec(A,A.hijoIzqdoB(n)) - alturarec(A,A.hijoDrchoB(n)));
        return maxi(diff,desequilibriorec(A,A.hijoIzqdoB(n)),desequilibriorec(A,A.hijoDrchoB(n)));
    }
}

template <typename T>
int desequilibrio(Abin<T>& A){
    return desequilibriorec(A,A.raizB());
}

/**************************************************************************************************Abin Pseudocompleto*/

template <typename T>
bool pseudocompletorec (Abin<T>& A,typename Abin<T>::nodo n){
    if(n==Abin<T>::NODO_NULO){
        return true;
    }else{
        if(altura(A)-1==prof_nodo(A,n)){
            if(is_sheet(A,n)||(A.hijoIzqdoB(n)!=Abin<T>::NODO_NULO && A.hijoDrchoB(n)!=Abin<T>::NODO_NULO)){//si es hoja o tiene dos hijos
                return true;
            }else{
                return false;
            }
        }
        return pseudocompletorec(A,A.hijoIzqdoB(n)) && pseudocompletorec(A,A.hijoDrchoB(n));
    }
}

template <typename T>
bool pseudocompleto (Abin<T>& A){
    return pseudocompletorec(A,A.raizB());
}




#endif //ABIN_EJERCICIOS_BASICOS_HPP
