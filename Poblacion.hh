/** @file Poblacion.hh
   @brief Classe Poblacion
 */
#ifndef POBLACIO_HH
#define POBLACIO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#endif
#include "Individuo.hh"
using namespace std;

/** @class Poblacion
    @brief Población representada por los individuos añadidos al sistema.
 */

class Poblacion {

private:
    
    /** @brief Lee el vector de strings parcial.
       \pre: Cierto.
       \post: parcial contiene los datos leidos del canal estandard de lectura en preorden
     */
    static void leer_parcial(vector<string> &parcial);
    
    /** @brief Completa recursivamente el vector completo a partir de
       \pre: nom es el nombre del individuo que estamos completando, i es la posicion del vector parcial donde se encuentra el nombre del individuo a analizar, completo hasta la posición i-esima esta completado.
       \post: el resultado indica si parcial es un arbol parcial del individuo "nom", en caso que sea cierto, completo contiene el arbol genealogico hasta la posicion i-esima completo
     */
    bool completar_rec(vector<string> &parcial, string nom, vector<string> &completo,int &i);
    
    /** @brief Añade a un vector la familia de un individuo
       \pre: nombre es el nombre de un individuo registrado en el sistema. 
       \post: Nos añade al vector v "$" si el individuo padre/madre del individuo no existe en el sistema y nos añadirá '*'nombre del padre/madre'*' si éste existe.
     */
    void anadir_familia_vector(string nombre, vector<string> &v);
    
    /** @brief Crea el arbol genealogico del individuo por niveles.
       \pre: nombre_individuo es el nombre del individuo que analizamos. v es el vector de colas de strings que lleva los antecesores en cada nivel y nivel es el nivel en el que estamos.
       \post: Crea el arbol genealogico del individuo nombre_individuo por niveles y lo añade al nivel "nivel" de v
     */
    void crear_niveles(string nombre_individuo, vector<queue<string> > &v, int nivel);
    
    /** @brief Añade un individuo a el vector de colas de strings por niveles.
       \pre:  nivel indica en qué nivel nos situamos.
       \post: Añade al individuo nombre_individuo al nivel "nivel" en v.
     */
    void anadir_individuo_nivel(string nombre_individuo, vector<queue<string> > &v, int nivel);
    
    /** @brief: Map que contiene todos los individuos registrados en el sistema.
     */
    map<string, Individuo> mpoblacion;

public:
    
    //Modificadores
    
    /** @brief Añade un  individuo al sistema.
     \pre: El individuo nombre_individuo no está en el pi todavía.
     \post: Se añade el nuevo individuo nombre_individuo al p.i.
     */
   void anadir_individuo(string nombre_individuo, Individuo& ind);
    
    /** @brief Añade un nuevo individuo a partir de dos individuos (hombre y mujer).
      \pre: Al pi existen el nombre_padre y la nombre_madre, pero no el nombre_hijo. Los padres no son hermanos ni hermanastros, y tampoco son antecesores entre ellos. El individuo indpadre es un hombre y el individuo indmadre es mujer.
      \post: Se añade el nuevo individuo con nombre nombre_hijo con el cruce de cromosomas del padre y de la madre. Se añaden los padres a el individuo.
     */
    void reproduccion_sexual(Individuo& indpadre, string nombre_padre, Individuo& indmadre, string nombre_madre, string nombre_hijo, int l0);
    
    /** @brief Busca en el p.i un individuo por su nombre.
      \pre: Al pi existe el individuo con nombre_individuo.
      \post: Nos devuelve el Individuo que corresponde al nombre nombre_individuo del p.i.
     */
    Individuo buscar_individuo(string nombre_individuo) const;
    
    //Consultores
    
    /** @brief Comprueba si el individuo está registrado en el sistema.
       \pre: Cierto.
       \post: Devuelve cierto si el individuo aparece registrado en el sistema. En casa contrario, devuelve falso.
     */
    bool existe(string nombre_individuo) const;
    
    /** @brief Comprueba si dos individuos son hermanos.
       \pre: n1 y n2 existen en el pi.
       \post: Devuelve cierto si los individuos son hermanos (comparten los dos padres) o hermanastros (comparten uno de ellos) y falso si no lo son.
     */
    bool son_hermanos(string n1, string n2) const;
    
    /** @brief Comprueba si n1 es antecesor de n2.
       \pre: n1 y n2 existen en el pi.
       \post: Devuelve cierto si n1 es un individuo que es antecesor de n2. En caso contrario, devuelve falso.
     */
    bool son_antecesores(string n1, string n2) const;

    /** @brief Nos dice si es un arbol es parcial o no. En caso de que sea arbol parcial, lo completa y lo escribe.
       \pre: cierto.
       \post: Nos dice si es un arbol parcial o no. En caso de que sea arbol parcial, lo completa y lo escribe.
     */
    bool completar_arbol_genealogico();
       
    //Escriptura

    /** @brief Escribe todos los individuos registrados en el sistema.
     \pre: Cierto.
     \post: Escribe todos los individuos registrados en el sistema.
     */
    void escribir_poblacion() const;
    
    /** @brief Crea un arbol genealogico de los antecesores de un individuo a partir de una funcion que crea los niveles y lo escribe.
       \pre: nombre_individuo es el nombre de el individuo y existe en el pi.
       \post: Escribe el arbol genealogico de los antecesores del individuo nombre_individuo por niveles.
     */
    void escribir_arbol_genealogico(string nombre_individuo);

};

#endif