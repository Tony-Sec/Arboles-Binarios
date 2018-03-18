#ifndef ABIN_HPP
#define ABIN_HPP

#include <cassert>

using namespace std;

template<typename T>
class Abin {
    struct celda;
// declaración adelantada privada
public:
    typedef celda *nodo;
    static const nodo NODO_NULO;

    class Error{
    public:
        Error(const char* c):porque(c){}
        const char* why() const{return porque;};
    private:
        const char* porque;
    };


    Abin();// constructor
    void insertarRaizB(const T &e);
    void insertarHijoIzqdoB(nodo n, const T &e);
    void insertarHijoDrchoB(nodo n, const T &e);
    void eliminarHijoIzqdoB(nodo n);
    void eliminarHijoDrchoB(nodo n);
    void eliminarRaizB();
    ~Abin();// destructor
    bool arbolVacioB() const;
    const T &elemento(nodo n) const; // acceso a elto, lectura
    T &elemento(nodo n);// acceso a elto, lectura/escritura
    nodo raizB() const;
    nodo padreB(nodo n) const;
    nodo hijoIzqdoB(nodo n) const;
    nodo hijoDrchoB(nodo n) const;
    Abin(const Abin<T> &a);// ctor. de copia
    Abin<T> &operator=(const Abin<T> &a); //asignación de árboles
private:
    struct celda {
        T elto;
        nodo padre, hizq, hder;

        celda(const T &e, nodo p = NODO_NULO) : elto(e),
                                                padre(p), hizq(NODO_NULO), hder(NODO_NULO) {}
    };

    nodo r;

// nodo raíz del árbol
    void destruirNodos(nodo &n);

    nodo copiar(nodo n);
};

/* Definición del nodo nulo */
template<typename T>
const typename Abin<T>::nodo Abin<T>::NODO_NULO=0;

template<typename T>
inline Abin<T>::Abin() : r(NODO_NULO) {}

template<typename T>
inline void Abin<T>::insertarRaizB(const T &e) {
    if(r == NODO_NULO) throw Error("Arbol vacio");
    r = new celda(e);
}

template<typename T>
inline void Abin<T>::insertarHijoIzqdoB(Abin<T>::nodo n,const T &e) {
    if(n != NODO_NULO) throw Error("Imposible insertar Hijo Izq :el nodo no es valido,debe ser nulo");
    if(n->hizq == NODO_NULO)throw Error("Imposible insertar Hijo Izq :hijo izq no existe");
    n->hizq = new celda(e, n);
}

template<typename T>
inline void Abin<T>::insertarHijoDrchoB(Abin<T>::nodo n, const T &e) {
    if(n != NODO_NULO) throw Error("Imposible insertar Hijo Der :el nodo no es valido,debe ser nulo");
    if(n->hder == NODO_NULO)throw Error("Imposible insertar Hijo Der:hijo der no existe");
    n->hder = new celda(e, n);
}

template<typename T>
inline void Abin<T>::eliminarHijoIzqdoB(Abin<T>::nodo n) {
    if(n != NODO_NULO) throw Error("Imposible eliminar Hijo Izq :el nodo no es valido,debe ser nulo");
    if(n->hizq != NODO_NULO)throw Error("Imposible eliminar Hijo Izq:el nodo tiene hijo izq");

    if(n->hizq->hizq == NODO_NULO &&n->hizq->hder == NODO_NULO)
        throw Error("Imposible eliminar Hijo Izq:El  hijo izq del nodo es hoja");
    delete (n->hizq);
    n->hizq = NODO_NULO;
}

template<typename T>
inline void Abin<T>::eliminarHijoDrchoB(Abin<T>::nodo n) {
    if(n != NODO_NULO) throw Error("Imposible eliminar Hijo Der :el nodo no es valido,debe ser nulo");
    if(n->hder != NODO_NULO)throw Error("Imposible eliminar Hijo Der:el nodo tiene hijo der");
    if(n->hder->hizq == NODO_NULO && n->hder->hder == NODO_NULO)
        throw Error("Imposible eliminar Hijo Der:El  hijo der del nodo es hoja");
    delete (n->hder);
    n->hder = NODO_NULO;
}

template<typename T>
inline void Abin<T>::eliminarRaizB() {
    if(r != NODO_NULO)throw Error("Imposible eliminar Raiz :Arbol no vacío");
    if(r->hizq == NODO_NULO && r->hder == NODO_NULO)
        throw Error("Imposible eliminar Raiz:La raiz es hoja");
    delete (r);
    r = NODO_NULO;
}

template<typename T>
inline Abin<T>::~Abin() {
    destruirNodos(r); // vacía el árbol
}

template<typename T>
inline bool Abin<T>::arbolVacioB() const { return (r == NODO_NULO); }

template<typename T>
inline const T &Abin<T>::elemento(Abin<T>::nodo n) const {
    assert(n != NODO_NULO);
    return n->elto;
}

template<typename T>
inline T &Abin<T>::elemento(Abin<T>::nodo n) {
    assert(n != NODO_NULO);
    return n->elto;
}

template<typename T>
inline typename Abin<T>::nodo Abin<T>::raizB() const {
    return r;
}

template<typename T>
inline
typename Abin<T>::nodo Abin<T>::padreB(Abin<T>::nodo n) const {
    assert(n != NODO_NULO);
    return n->padre;
}

template<typename T>
inline
typename Abin<T>::nodo Abin<T>::hijoIzqdoB(Abin<T>::nodo n) const {
    assert(n != NODO_NULO);
    return n->hizq;
}

template<typename T>
inline
typename Abin<T>::nodo Abin<T>::hijoDrchoB(Abin<T>::nodo n) const {
    assert(n != NODO_NULO);
    return n->hder;
}

template<typename T>
inline Abin<T>::Abin(const Abin<T> &a) {
    r = copiar(a.r);
}

template<typename T>
Abin<T> &Abin<T>::operator=(const Abin<T> &a) {
    if (this != &a){// evitar autoasignación
        this->~Abin();// vaciar el árbol
        r = copiar(a.r);
    }
    return *this;
}

// Métodos privados
// Destruye un nodo y todos sus descendientes
template<typename T>
void Abin<T>::destruirNodos(Abin<T>::nodo &n) {
    if (n != NODO_NULO) {
        destruirNodos(n->hizq);
        destruirNodos(n->hder);
        delete n;
        n = NODO_NULO;
    }
}

// Devuelve una copia de un nodo y todos sus descendientes
template<typename T>
typename Abin<T>::nodo Abin<T>::copiar(Abin<T>::nodo n) {
    nodo m = NODO_NULO;
    if (n != NODO_NULO) {
        m = new celda(n->elto);// copiar n
        m->hizq = copiar(n->hizq); // copiar subárbol izqdo.
        if (m->hizq != NODO_NULO)
            m->hizq->padre = m;
        m->hder = copiar(n->hder); // copiar subárbol drcho.
        if (m->hder != NODO_NULO)
            m->hder->padre = m;
    }
    return m;
}

#endif // ABIN_HPP
