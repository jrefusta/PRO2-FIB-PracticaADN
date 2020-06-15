#include "Individuo.hh"
 
    Individuo::Individuo(){}    
    Individuo::Individuo(int N){
        vector_cromosomas = vector<Par_Cromosomas>(N+1);
    }

    bool Individuo::genero() const {
        if (composicion_genetica == 'X') return true;
        else return false;
    }
    
    pair<bool, string>  Individuo::tiene_padre() const {
        pair<bool, string> p;
        p.second = padre;
        if (padre == "$") p.first = false;
        else p.first = true;
        return p;
    }

    pair<bool, string>  Individuo::tiene_madre() const {
        pair<bool, string> m;
        m.second = madre;
        if (madre == "$") m.first = false;
        else m.first = true;
        return m;
    }

    void Individuo::escribir_genotipo() {
        vector_cromosomas[0].escribir_cromosomas_sex(composicion_genetica);
        escribir_cromosomas_nor();
    }
    
    
    void Individuo::escribir_cromosomas_nor() {
        for (int i = 1; i < vector_cromosomas.size(); ++i) {
            vector_cromosomas[i].escribir_cromosomas_nor(i);
        }
    }

    void Individuo::leer_comp_gen_y_cromosomas_sex(int lx, int ly) {
        cin >> composicion_genetica;
        vector_cromosomas[0].leer_cromosomas_sex(lx, ly, composicion_genetica);
    }
    
    void Individuo::leer_cromosomas_nor(int posicion, int numero_genes) {
        vector_cromosomas[posicion].anadir_cromosomas_nor(numero_genes);
    }
    
    void Individuo::anadir_padres(string p, string m) {
        madre = m;
        padre = p;
    }
    
    void Individuo::reproducir_padres(Individuo& padre, Individuo& madre, int l0) {
        //cout << "reproducir_padres " << l0 << endl;
        for (int i = 0; i < padre.vector_cromosomas.size(); ++i) {
            if (i == 0) {
                Par_Cromosomas c;
                char composicion_genetica_n;
                c.cruzar_sexual(padre.vector_cromosomas[i], madre.vector_cromosomas[i], l0, composicion_genetica_n);
                composicion_genetica = composicion_genetica_n;
                vector_cromosomas.push_back(c);
            }
            else {
                Par_Cromosomas c;
                c.cruzar_normal(padre.vector_cromosomas[i], madre.vector_cromosomas[i]);
                vector_cromosomas.push_back(c);
            }
        }
    }