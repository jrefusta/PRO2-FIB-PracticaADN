/** @file arbol.hh
   @brief Classe Arbol
 */
#ifndef ARBOL_HH
#define ARBOL_HH

#include <iostream>
#include <vector>
#include "Poblacion.hh"
using namespace std;

/** @class Arbol
    @brief Arbre genealogic afegit al sistema.
  */

class Arbol {
    
private: 

    
public:
    
    //Escriptura
       
    //Modificadoras
    
    /** @brief Completa el nostre arbre parcial amb els individus de la seva familia que tenim registrat al sistema
       \pre: cert
       \post: completa el arbre genealogic i ens diu si es parcial o no.
     */
    bool completar_arbol_genealogico();
    
    //Consultoras
    
    /** @brief Ens indica si l'arbre genealogic es un arbre parcial
       \pre: cert
       \post: es cert si l'arbre genaelogic es un arbre parcial.
     */
    bool es_parcial();
};

#endif