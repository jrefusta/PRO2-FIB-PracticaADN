/** @file Individuo.hh
   @brief Clase Individuo
 */
#ifndef INDIVIDUO_HH
#define INDIVIDUO_HH

#include <iostream>
#include <vector>
#include "Par_Cromosomas.hh"
using namespace std;

/** @class individuo
    @brief Representa un individuo
  */

class Individuo {
    
private:
    char composicion_genetica;
    vector<Par_Cromosomas> vector_cromosomas;
    string madre, padre;
    
public:
    //Constructoras
    
     /** @brief Creación de un individu.
      */
    Individuo();
    
   /** @brief Genera un vector de Par de cromosomas de mida N+1.
        \pre: N es el numero de pares de cromosomas normales que tiene el individuo
        \post: Genera un vector de Par de cromosomas de mida N+1.
     */ 
    Individuo(int N);

    //Consultoras
    
    /** @brief Comprueba el genero de un individuo
       \pre: Cierto.
       \post: Nos devuelve falso si el genero del individuo es femenino y cierto si es masulino.
     */
    bool genero() const;
    
    /** @brief Nos dice de un individuo si tiene padre o no. En caso de que tenga, nos dirá también su nombre.
       \pre: Cierto.
       \post: Si tiene padre, la primera parte del pair será cierta  si no, será falsa. La segunda parte del pair nos dice el nombre del padre, en el caso de que no tenga padre registrado en el sistema, su nombre será "$".
     */
    pair<bool, string> tiene_padre() const;
    
    /** @brief Nos dice de un individuo si tiene madre o no. En caso de que tenga, nos dirá también su nombre.
       \pre: Cierto.
       \post: Si tiene madre, la primera parte del pair será cierta  si no, será falsa. La segunda parte del pair nos dice el nombre de la madre, en el caso de que no tenga madre registrada en el sistema, su nombre será "$".
     */ 
    pair<bool, string> tiene_madre() const;
    
    //Escriptura i Lectura
    
    /** @brief Escribe el genotipo de un individuo.
      \pre: Cierto.
      \post: Escribe el genotipo de un individuo llamando a una funcion para escribir los cromosomas sexuales y otra para los normales.
     */
    void escribir_genotipo();
    
    /** @brief Lee la composicion genetica y los cromosomas sexuales de un individuo. 
      \pre: lx es la longitud del primer vector de cromosomas del par de cromosomas sexuales de el individuo y ly el segundo. lx y ly no son vacios.
      \post: Llegeix la composicio genetica i els cromosomes sexuals de un individu
     */
    void leer_comp_gen_y_cromosomas_sex(int lx, int ly);
    
    /** @brief Lee los cromosomas normales de un individuo en una posicion específica.
      \pre: posicion es la posicion de el vector de cromosomas y el numero_genes es el numero de genes que tiene el vector de cromosomas en si.
      \post: Lee los cromosomas normales de un individuo en una posicion específica.
     */
    void leer_cromosomas_nor(int posicion, int numero_genes);
    
    /** @brief 
      \pre: cert
      \post: Llix
    */ 
    void reproducir_padres(Individuo& padre, Individuo& madre, int l0);
    
    /** @brief Añade unos padres al individuo.
      \pre: Individuo existe en el pi. p es el nombre del padre y m el de la madre.
      \post: Añade padres al individuo.
    */ 
    void anadir_padres(string p, string m);

    /** @brief Escribe los cromosomas normales del individuo.
      \pre: Cierto.
      \post: Escribe los cromosomas normales del individuo.
    */ 
    void escribir_cromosomas_nor();

}; 

#endif