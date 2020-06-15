/** @file Par_Cromosomas.hh
   @brief Classe Par_Cromosomas
 */
#ifndef PAR_CROMOSMAS_HH
#define PAR_CROMOSOMAS_HH

#include <iostream>
#include <vector>
using namespace std;

/** @class Par_Cromosmas
    @brief Representa un parell de cromosmes
  */

class Par_Cromosomas {
    
private:   
    vector<int> c1;
    vector<int> c2;
    
public:
    
    Par_Cromosomas();
    //Escriptura i lectura

     /** @brief Lee el par de cromosomas sexuales de el individuo y su composicion genetica.
        \pre: Composicion genetica es X o Y, ly y lx no son vacíos.
        \post: Registra el par de cromosomas sexuales del individuo y su composicion genetica. El primer vector del par de cromosomas sexuales tendrá longitud lx y el segundo ly en el caso de que su composicion genetica sea Y, y lx en el caso de que composicion genetica sea X.
     */
    void leer_cromosomas_sex(int lx, int ly, char composicion_genetica);
  
    /** @brief Leerá y registrará en el sistema un par de cromosomas normales del individuo.
        \pre: num_genes es el numero de genes del individuo que tiene en un cromosoma en específico.
        \post: Añadimos un par de cromosomas normales de un individuo.
     */
    void anadir_cromosomas_nor(int num_genes);
    
    /** @brief Esribe un par de cromosmas sexuales de un individuo.
        \pre: c es X o Y.
        \post: Escribe un par de cromosmas sexuales de un individuo.
     */
    void escribir_cromosomas_sex(char c);
    
    /** @brief Esribe un par de cromosmas normales de un individuo.
        \pre: i es la posicion 1<=i<=N donde se encuentra un par de cromosomas normales.
        \post: Escribe un par de cromosmas normales de un individuo.
     */
    void escribir_cromosomas_nor(int i);
    
    
    void cruzar_sexual(Par_Cromosomas& padre, Par_Cromosomas& madre, int l0, char& composicion_genetica_n);
    void cruzar_normal(Par_Cromosomas& padre, Par_Cromosomas& madre);



};

#endif