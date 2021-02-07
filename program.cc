#include <iostream>
#include <vector>
#include <string>
#include "Poblacion.hh"
using namespace std;

int main() {    
    int N;
    cin >> N;
    int lx, ly;
    vector <int> l(N+1);
    for (int i = 0; i <= N; ++i) {
        cin >> l[i];
    }
    cin >> lx >> ly;
    int M;
    cin >> M;
    string nombre_individuo;
    Poblacion p;
    for (int i = 0; i < M; ++i) {
        Individuo ind(N);
        cin >> nombre_individuo;
        ind.leer_comp_gen_y_cromosomas_sex(lx, ly);
        for (int j = 1; j <= N; ++j) {
            ind.leer_cromosomas_nor(j, l[j]);       
        }
        ind.anadir_padres("$", "$");
        p.anadir_individuo(nombre_individuo,ind);
    }
    string funciones;
    cin >> funciones;
    while (funciones != "acabar") {
        if (funciones == "anadir_individuo") {
            Individuo ind(N);
            cin >> nombre_individuo;
            cout << "anadir_individuo " << nombre_individuo << endl;
            ind.leer_comp_gen_y_cromosomas_sex(lx, ly);
            for (int i = 1; i <= N; ++i) {
                ind.leer_cromosomas_nor(i, l[i]);
            }
            if (not p.existe(nombre_individuo)) {
                ind.anadir_padres("$", "$");
                p.anadir_individuo(nombre_individuo, ind);
            }
            else cout << "  error" << endl;
        }
        else if (funciones == "reproduccion_sexual") {
            string padre, madre, hijo;
            cin >> madre >> padre >> hijo;  
            cout << "reproduccion_sexual " << madre << ' ' << padre << ' ' << hijo << endl;
            if (p.existe(padre) and p.existe(madre) and not p.existe(hijo)) {
                Individuo indpadre = p.buscar_individuo(padre);
                Individuo indmadre = p.buscar_individuo(madre);
                if (not indpadre.genero() and  indmadre.genero() and not p.son_hermanos(padre, madre) and not p.son_antecesores(padre, madre) and not p.son_antecesores(madre, padre)) {
                        p.reproduccion_sexual(indpadre, padre, indmadre, madre, hijo, l[0]);
                }
                else cout << "  no es posible reproduccion" << endl;
            }
            else cout << "  error" << endl;
        }
        else if (funciones == "escribir_arbol_genealogico") {
            cin >> nombre_individuo;
            cout << "escribir_arbol_genealogico " << nombre_individuo << endl;
            if (p.existe(nombre_individuo)) p.escribir_arbol_genealogico(nombre_individuo);
            else cout << "  error" << endl;
        }
        else if (funciones == "completar_arbol_genealogico") {
            if (not p.completar_arbol_genealogico()) {
                cout << " no es arbol parcial" << endl;
            }
        } 
        else if (funciones == "escribir_poblacion") {
            p.escribir_poblacion();
        }
        else if (funciones == "escribir_genotipo") {
            cin >> nombre_individuo;
            cout << "escribir_genotipo " << nombre_individuo << endl;
            if (p.existe(nombre_individuo)) {
                Individuo ind = p.buscar_individuo(nombre_individuo);
                ind.escribir_genotipo();
            }
            else cout << "  error" << endl;
        }
        cin >> funciones;
    }
    cout << "acabar" << endl;
}