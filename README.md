# Estructura de Datos No Lineales
## Arboles-Binarios

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
      
  
![Texto alternativo](http://img.fenixzone.net/i/lmTtJ8j.jpeg)
Proyecto destinado a la enseñanza de Estructuras de datos no lineales
