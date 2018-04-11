#ifndef EJERCICIOS_AVANZADOS_ABIN_HPP
#define EJERCICIOS_AVANZADOS_ABIN_HPP


#include "../A_bin_dinamico.hpp"
#include "../Ejercicios_basicos_Abin/Ejercicios_basicos_Abin.hpp"

/**********************************************************************************Árboles Binarios Similares*/
/* Que sean similares ambos árboles no quiere decir que sean identicos ,es decir,
 * que pueden tener igual estructura pero el contenido del nodo es diferente
 */
template <typename T>
bool similaresrec(const Abin<T>& A,const Abin<T>& B,typename Abin<T>::nodo a,typename Abin<T>::nodo b){

    if(a==b&&a==Abin<T>::NODO_NULO)return true;//Arbol vacio o terminado la rama
    else{
        if(a!=b&&a==Abin<T>::NODO_NULO) return false;//Son diferentes
        else return  similaresrec(A,B,A.hijoIzqdoB(a),B.hijoIzqdoB(b))
                     && similaresrec(A,B,A.hijoDrchoB(a),B.hijoDrchoB(b));

    }

}

template <typename T>
bool similares(const Abin<T>& A,const Abin<T>& B){
    return similaresrec(A,B,A.raizB(),B.raizB());
}

/**********************************************************************************************Árbol Binario reflejado*/

template <typename T>
void reflejadorec(Abin<T>& A,Abin<T>& B,typename Abin<T>::nodo a,typename Abin<T>::nodo b){

    if(a!=Abin<T>::NODO_NULO){
        if(A.hijoIzqdoB(a)!=Abin<T>::NODO_NULO){
            B.insertarHijoDrchoB(b,A.elemento(A.hijoIzqdoB(a)));
            reflejadorec(A,B,A.hijoIzqdoB(a),B.hijoDrchoB(b));
        }
        if(A.hijoDrchoB(a)!=Abin<T>::NODO_NULO){
            B.insertarHijoIzqdoB(b,A.elemento(A.hijoDrchoB(a)));
            reflejadorec(A,B,A.hijoDrchoB(a),B.hijoIzqdoB(b));
        }
    }
}

template <typename T>
Abin<T> reflejado(Abin<T>& A){
    Abin<T> B;
    if(!A.arbolVacioB()){
        B.insertarRaizB(A.elemento(A.raizB()));
        cout<<B.elemento(B.raizB())<<endl;
        reflejadorec(A,B,A.raizB(),B.raizB());
    }
    return B;
}

/********************************************************************************Árbol Binario de expresión aritmetica*/

struct nodoArit{
    char operador;
    double operando;
    nodoArit(char operador = '#', double operando = 0) : operador(operador),
                                                         operando(operando){}
};

istream& operator >>(istream &i, nodoArit& n){
    cout << "Introducir valores para operador y despues para operando: ";
    i >> n.operador >> n.operando;
    i.ignore();
    return i;
}
ostream& operator <<(ostream &o,const nodoArit& n){
    o << n.operador << n.operando;
    return o;
}
bool operator !=(const nodoArit& izq,const nodoArit& der){
    bool ret;
    if(izq.operador == der.operador && izq.operando == der.operando)
        ret = false;
    else
        ret = true;
    return ret;
}

template <typename T>
int exp_Abinrec (Abin<T>& A,typename Abin<T>::nodo n){

    if(is_sheet(A,n)) return A.elemento(n);
    switch (A.elemento(n)){
        case '*':
            return exp_Abinrec(A,A.hijoIzqdoB(n))*exp_Abinrec(A,A.hijoDrchoB(n));
        case '+':
            return exp_Abinrec(A,A.hijoIzqdoB(n))+exp_Abinrec(A,A.hijoDrchoB(n));
        case '-':
            return exp_Abinrec(A,A.hijoIzqdoB(n))-exp_Abinrec(A,A.hijoDrchoB(n));
        case '/':
            return exp_Abinrec(A,A.hijoIzqdoB(n))/exp_Abinrec(A,A.hijoDrchoB(n));
        default:
            cout<<"ERROR!"<<endl;
    }
    return 0;
}

template <typename T>
int exp_Abin (Abin<T>& A){
    return exp_Abinrec(A,A.raizB());
}

#endif //EJERCICIOS_AVANZADOS_ABIN_HPP
