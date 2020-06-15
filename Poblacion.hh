/** @file Poblacio.hh
   @brief Classe Poblacion
 */
#ifndef POBLACIO_HH
#define POBLACIO_HH

#include <iostream>
#include <vector>
#include <map>
#include "Individuo.hh"
using namespace std;

/** @class Poblacion
    @brief Població representada per els individus afegits al sistema
  */

class Poblacion {

private:
    
    /** @brief: Map que contiene todos los individuos del sistema.*/
    map<string, Individuo> mpoblacion;
    

public:
    
    //Escriptura

    /** @brief Escribe todos los individuos registrados en el sistema.
     \pre: Cierto.
     \post: Escribe todos los individuos registrados en el sistema.
     */
    void escribir_poblacion() const;
    
    //Modificadores
    
    /** @brief Añade un  individuo al sistema.
     \pre: El individuo no está en el pi  todavía.
     \post: Se añade un nuevo individuo al map mpoblacion.
     */
   void anadir_individuo(string nombre_individuo, Individuo& ind);
    
    /** @brief Añade un nuevo individuo a partir de dos individuos (hombre y mujer).
      \pre: Al pi existen el padre y la madre, pero no el hijo. Los padres no son hermanos ni hermanastros, y tampoco son antecesores entre ellos.
      \post: Se añade un nuevo individuo con el cruce de cromosomas del padre y de la madre.
      */
    void reproduccion_sexual(Individuo& indpadre, string nombre_padre, Individuo& indmadre, string nombre_madre, string nombre_hijo, int l0);
    
    //Modificadores
    
    /** @brief Busca en el mapa mpoblacion el individuo por su nombre.
      \pre: Al pi existe el individuo.
      \post: Nos devuelve el Individuo que pertece al nombre.
     */
    Individuo buscar_individuo(string nombre_individuo);
    
    //Consultores
    
    /** @brief Comprueba si el individuo está registrado en el sistema.
       \pre: Cierto.
       \post: Devuelve cierto si el individuo aparece registrado en el sistema.
     */
    bool existe(string nombre_individuo);
    
     /** @brief Comprueba si dos infividuos son hermanos.
       \pre: n1 y n2 existen en el pi.
       \post: Devuelve cierto si los individuos sin hermanos o hermanastros y falso si no lo son.
     */
    bool son_hermanos(string n1, string n2);
    
     /** @brief Comprueba si n1 es antecesor de n2.
       \pre: n1 y n2 existen en el pi.
       \post: Devuelve cierto si n1 es un individuo que es antecesor de n2.
       */
    bool son_antecesores(string n1, string n2);
    
    
        void escribir_arbol_genealogico(string nombre_individuo);

};

#endif