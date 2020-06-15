/** @file poblacio.hh
   @brief Classe Poblacio
 */
#ifndef POBLACIO_HH
#define POBLACIO_HH

#include <iostream>
#include <vector>
#include <map>
#include "individuo.hh"
#include "par_cromosomas.hh"
using namespace std;

/** @class poblacio
    @brief Població representada per els individus afegits al sistema
  */

class Poblacio {

private:
    
    /** @brief: Map que conte tots els individus afegits al sistema.*/
    map<string, Individu> Poblacio;

public:
    
    //Escriptura

    /** @brief Escribe todos los individuos registrados en el sistema.
     \pre: cert.
     \post: escriu els 
     */
    void escribir_poblacion() const;
    
    //Modificadores
    
    /** @brief Añade un  individuo al sistema.
     \pre: L'individu no és al pi encara
     \post: s'ha afegit un nou individu al pi
     */
    void anadir_individuo(const individuo &i);
    
    /** @brief Produeix un nou individu donat un pare i una mare vàlids
      \pre: Al pi existeixen el pare i la mare, però no el nou individu.
      \post: Es crea un nou individu.
     */
    void reproduccion_sexual(string nom_pare, string nom_mare, string nom_fill);
    
    //Modificadores
    
    /** @brief Busca al map de poblacio l'individu seleccionat.
      \pre: Al pi existeix l'individu
      \post: Ens retorna el Individu
     */
    Individuo buscar_individuo(string nom);
    
    
    //Consultores
    
    /** @brief Comprova si l'individu ja està registrat al sistema.
       \pre: cert
       \post: cert si l'individu apareix registrat en el sistema.
     */
    bool existeix(string nom_individu);
    
     /** @brief Comprova si els dos individus son germans
       \pre: cert
       \post: ens retorna cert si els dons individus son germans (comparteixen pare i/o mare)
     */
    bool son_germans(string nom_pare, string nom_mare);
    
     /** @brief Comprova si algun individu es antecesor de l'altre
       \pre: cert
       \post: ens retorna cert si algun dels dos individus és antecesor de l'altre.
     */
    bool son_antecesors(string nom_pare, string nom_mare);
};

#endif