# Estructura de Datos No Lineales
## Arboles-Binarios  
  
  ***************************************************************************************************************************
  Bienvenido !!!!!!!
  
  Para seguir esta guía[en construcción] he subido a este repositorio algunos ejercicios frecuentes que usan Árboles Binarios.
  Estan dividios en Ejercicios basicos y avanzados.Buen código!!!!!
  ***************************************************************************************************************************
  
Este repositorio contiene una serie de Bibliotecas en `C++` :
  
  * **A_bin_vectorial_pseu.hpp**  
      Biblioteca para representación en una estructura vectorial pseudoestática.
  * **A_bin_vectorial_posiciones_relativas.hpp**  
      Biblioteca para representación en una estructura vectorial mediante posiciones relativas.  
  * **A_bin_dinamico.hpp**  
      Biblioteca para representación en una estrucura dinámica mediante celdas enlazadas con punteros.  
      
  * **E_S_Abin.hpp**  
      Biblioteca para pruebas de Entrada y Salida de Árboles Binarios que muestra o guarda Árboles Binarios.  
   
 Y una serie de carpetas:  
   
  * **I-O_Abin**  
      Ejemplo de como usar la biblioteca de Entrada/Salida.
  * **Ejercicios_basicos_Abin**  
      Ejercicios basicos sobre Arboles Binarios.
   * **Ejercicios_avanzados_Abin**  
      Ejercicios avanzados sobre Arboles Binarios.     
      
      ***************************************************************************************************************************
              
      Especificación semántica y sintáctica del TAD Árbol Binario independiente de la representación elejida:  
      * *`Abin ()`*    
      Post: Crea y devuelve un árbol vacío.  
      * *`void insertarRaizB (const T& e)`*  
      Pre: El árbol está vacío.  
      Post: Inserta el nodo raíz cuyo contenido será e.  
      * *`void insertarHijoIzqdoB (nodo n, const T& e)`*  
      Pre: n es un nodo del árbol que no tiene hijo izquierdo.  
      Post: Inserta el elemento e como hijo izquierdo del nodo n.  
      * *`void insertarHijoDrchoB (nodo n, const T& e)`*  
      Pre: n es un nodo del árbol que no tiene hijo derecho.  
      Post: Inserta el elemento e como hijo derecho del nodo n.  
      * *`void eliminarHijoIzqdoB (nodo n)`*  
      Existe hijoIzqdoB(n) y es una hoja.  
        
        Pre: n es un nodo del árbol.  
        Post: Destruye el hijo izquierdo del nodo n.  
      * *`void eliminarHijoDrchoB (nodo n)`*  
      Existe hijoDrchoB(n) y es una hoja.  
        
        Pre: n es un nodo del árbol.  
        Post: Destruye el hijo derecho del nodo n.  
      * *`void eliminarRaizB ()`*  
      Pre: El árbol no está vacío y raizB() es una hoja.  
      Post: Destruye el nodo raíz. El árbol queda vacío  
      * *`bool arbolVacioB () const`*  
      Post: Devuelve true si el árbol está vacío y false en caso contrario.  
      * *`const T& elemento(nodo n) const`*  
        *`T& elemento(nodo n)`*  
      Pre: n es un nodo del árbol.  
      Post: Devuelve el elemento del nodo n.  
      * *`nodo raízB () const`*  
      Post: Devuelve el nodo raíz del árbol. Si el árbol está vacío, devuelve
      NODO_NULO.   
      * *`nodo padreB (nodo n) const`*  
      Pre: n es un nodo del árbol.  
      Post: Devuelve el padre del nodo n. Si n es el nodo raíz, devuelve
      NODO_NULO.  
      * *`nodo hijoIzqdoB (nodo n) const`*  
      Pre: n es un nodo del árbol.  
      Post: Devuelve el nodo hijo izquierdo del nodo n. Si no existe, devuelve
      NODO_NULO.  
      * *`nodo hijoDrchoB (nodo n) const`*  
      Pre: n es un nodo de A.  
      Post: Devuelve el nodo hijo derecho del nodo n. Si no existe, devuelve
      NODO_NULO.  
      
  
![Texto alternativo](http://img.fenixzone.net/i/lmTtJ8j.jpeg)
Proyecto destinado a la enseñanza de Estructuras de datos no lineales
