/** @file Individuo.hh
   @brief Clase Individuo
 */
#ifndef INDIVIDUO_HH
#define INDIVIDUO_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

#include "Par_Cromosomas.hh"
using namespace std;

/** @class Individuo
    @brief Representa un individuo.
  */

class Individuo {
    
private:
    
    char composicion_genetica;
    vector<Par_Cromosomas> vector_cromosomas;
    string madre, padre;
    
public:
    
    //Constructoras
    
    /** @brief Creación de un individu.
        \pre: cierto
        \post: se crea un Individuo vacio
     */
    Individuo();
    
    /** @brief Genera de Par de cromosomas de mida N+1.
        \pre: N es el numero de pares de cromosomas normales que tiene el individuo
        \post: Genera un conjunto de Par de cromosomas de mida N+1.
     */ 
    Individuo(int N);

    //Modificadoras
    
    /** @brief Reproduce los padres de el individuo creando el nuevo par de cromosomas de el nuevo individuo.
      \pre: l0 es el numero de genes comunes de los cromosomas sexuales, l0 > 0. padre y madre son los Individuos cuyos cromosomas vamos a cruzar y que se pueden cruzar.
      \post: Reproduce los padres de el individuo creando los nuevos pares de cromosomas de el nuevo individuo.
     */ 
    void reproducir_padres(Individuo& padre, Individuo& madre, int l0);
    
    /** @brief Añade unos padres al individuo.
      \pre: cierto
      \post: Añade los padres p y m al individuo del p.i.
     */ 
    void anadir_padres(string p, string m);

    //Consultoras
    
    /** @brief Comprueba el genero de un individuo
       \pre: Cierto.
       \post: Nos devuelve falso si el genero del individuo es femenino y cierto si es masulino.
     */
    bool genero() const;
    
    /** @brief Nos dice de un individuo si tiene padre o no y su nombre.
       \pre: Cierto.
       \post: Si tiene padre, la primera parte del pair será cierta, si no, será falsa. La segunda parte del pair nos dice el nombre del padre, en el caso de que no tenga padre registrado en el sistema, su nombre será "$".
     */
    pair<bool, string> tiene_padre() const;
    
    /** @brief Nos dice de un individuo si tiene madre o no y su nombre.
       \pre: Cierto.
       \post: Si tiene madre, la primera parte del pair será cierta  si no, será falsa. La segunda parte del pair nos dice el nombre de la madre, en el caso de que no tenga madre registrada en el sistema, su nombre será "$".
     */ 
    pair<bool, string> tiene_madre() const;
    
    //Escritura y Lectura
    
    /** @brief Escribe el genotipo de un individuo.
      \pre: Cierto.
      \post: Escribe el genotipo del individuo del p.i.
     */
    void escribir_genotipo();
    
    /** @brief Lee la composicion genetica y los cromosomas sexuales de un individuo. 
      \pre: lx es la longitud del primer cromosoma del par de cromosomas sexuales de el individuo del p.i y ly es la del  segundo. lx > 0 y ly > 0 .
      \post: Lee la composicion genetica y los cromosomas sexuales del individuo del p.i. 
     */
    void leer_comp_gen_y_cromosomas_sex(int lx, int ly);
    
    /** @brief Lee los cromosomas normales de un individuo en una posicion específica.
      \pre: posicion es la posicion del gen del cromosoma y el numero_genes es el numero de genes que tiene cromosomas en si.
      \post: Lee los cromosomas normales del individuo del p.i en la posicion "posicion".
     */
    void leer_cromosomas_nor(int posicion, int numero_genes);
    
    /** @brief Escribe los cromosomas normales del individuo.
      \pre: Cierto.
      \post: Escribe los cromosomas normales del individuo.
     */ 
    void escribir_cromosomas_nor();
    
}; 

#endif