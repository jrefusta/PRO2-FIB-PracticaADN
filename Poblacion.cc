#include "Poblacion.hh"

    void Poblacion::anadir_individuo(string nombre_individuo, Individuo& ind) {
        mpoblacion.insert(pair<string,Individuo> (nombre_individuo, ind));
    }
        
    void Poblacion::escribir_poblacion () const {
        map<string, Individuo>::const_iterator it = mpoblacion.begin();
        cout << "escribir_poblacion" << endl;
        while (it != mpoblacion.end()) {
            cout << "  " << (*it).first;
            if ((*it).second.genero()) cout << " XX ";
            else  cout << " XY ";
            pair<bool, string> tm, tp;
            tm = (*it).second.tiene_madre();
            tp = (*it).second.tiene_padre();
            cout << '(' << tp.second << ',' << tm.second << ')' << endl;
            ++it;
        }
    }

    bool Poblacion::existe(string nombre_individuo) const {
        map<string, Individuo>:: const_iterator it = mpoblacion.begin();
        while (it != mpoblacion.end()) {
            if ((*it).first == nombre_individuo) return true;
            ++it;
        }
        return false;
    }

    Individuo Poblacion::buscar_individuo(string nombre_individuo) const {
        map<string, Individuo>:: const_iterator it = mpoblacion.begin();
        while (it != mpoblacion.end()) {
            if ((*it).first == nombre_individuo) return (*it).second; 
            ++it;
        }
        return Individuo();
    }
        
    void Poblacion::reproduccion_sexual(Individuo& indpadre, string nombre_padre, Individuo& indmadre, string nombre_madre, string nombre_hijo, int l0) {
        Individuo indhijo;
        indhijo.anadir_padres(nombre_padre, nombre_madre);
        indhijo.reproducir_padres(indpadre, indmadre, l0);
        anadir_individuo(nombre_hijo, indhijo);
    }

    bool Poblacion::son_hermanos(string nombre_padre, string nombre_madre) const {
        Individuo indpadre = buscar_individuo(nombre_padre);
        Individuo indmadre = buscar_individuo(nombre_madre);
        if (indpadre.tiene_madre().first == true and indmadre.tiene_madre().first == true) {
            if (indpadre.tiene_madre().second == indmadre.tiene_madre().second or indpadre.tiene_padre().second == indmadre.tiene_padre().second) return true;
        }
        return false;
    }

    bool Poblacion::son_antecesores(string n1, string n2) const {
        Individuo ind = buscar_individuo(n2); 
        if (ind.tiene_madre().first == false) return false;
        else if (ind.tiene_madre().second == n1 or ind.tiene_padre().second == n1) return true;
        else {
            return (son_antecesores(n1, ind.tiene_madre().second) or son_antecesores(n1, ind.tiene_padre().second));
        }
    }

    void Poblacion::escribir_arbol_genealogico(string nombre_individuo) {
        vector<queue<string> > niveles;
        crear_niveles(nombre_individuo, niveles, 0);
        for (int i = 0; i < niveles.size(); ++i) {
            cout << "  Nivel " << i << ':';
            while(not niveles[i].empty()) {
                cout << ' ' << niveles[i].front();
                niveles[i].pop();
            }
            cout << endl;
        }
    }

    void Poblacion::anadir_individuo_nivel(string nombre_individuo, vector<queue<string> > &v, int nivel) {
        if (nivel >= v.size()) v.push_back(queue<string>());
        v[nivel].push(nombre_individuo);
    }

    void Poblacion::crear_niveles(string nombre_individuo, vector<queue<string> > &v, int nivel) {
        if (nombre_individuo != "$") {
            Individuo ind = buscar_individuo(nombre_individuo);
            anadir_individuo_nivel(nombre_individuo, v, nivel);
            if (ind.tiene_madre().first) {
                string nombre_padre = ind.tiene_padre().second;
                string nombre_madre = ind.tiene_madre().second;
                crear_niveles(nombre_padre, v, nivel+1);
                crear_niveles(nombre_madre, v, nivel+1);
            }
        }
    }

    bool Poblacion::completar_arbol_genealogico() {
        vector<string> parcial;
        vector<string> completo;
        leer_parcial(parcial);
        cout << "completar_arbol_genealogico" << " " << parcial[0] << endl<< ' ';
        int i = 0;
        bool es_parcial = existe(parcial[0]);
        if (es_parcial) es_parcial = completar_rec(parcial, parcial[0], completo,i);
        if (not es_parcial) return false;
        else {
            for(int i = 0; i < completo.size(); ++i) cout << ' ' << completo[i];
            cout << endl;
            return true;
        }
    }

     bool Poblacion::completar_rec(vector<string> &parcial, string nom, vector<string> &completo,int &i) {
        if (i < parcial.size()) {
            string nombre_individuo = parcial[i];
            if (nom == nombre_individuo) {
                completo.push_back(nombre_individuo);
                if(nom != "$") {
                   Individuo ind = buscar_individuo(nombre_individuo);
                   string nombre_padre = ind.tiene_padre().second;
                   string nombre_madre = ind.tiene_madre().second;
                   ++i;
                   bool b = completar_rec(parcial, nombre_padre,completo,i);
                   if (b) {
                        ++i;
                        b = completar_rec(parcial,nombre_madre, completo,i);
                   }
                   return b;
                }
                else return true;
            }
            else {
                if (nom == "$") return false;
                else if (nombre_individuo == "$"){
                    anadir_familia_vector(nom, completo);
                    return true;
                }
                else return false;
            }
        }
        else return true;
    }

    void Poblacion::leer_parcial(vector<string> &parcial){
        string x;
        cin >> x;
        if(x == "$") parcial.push_back("$");
        else{
            parcial.push_back(x);
            leer_parcial(parcial);
            leer_parcial(parcial);
        }
    }

    void Poblacion::anadir_familia_vector(string nombre, vector<string> &v) {
            Individuo ind = buscar_individuo(nombre);
            v.push_back("*"+nombre+"*");
            if(ind.tiene_padre().first) anadir_familia_vector(ind.tiene_padre().second,v);
            else v.push_back("$");
            if(ind.tiene_madre().first) anadir_familia_vector(ind.tiene_madre().second,v);
            else v.push_back("$");
    }