#include "Poblacion.hh"

void Poblacion::anadir_individuo(string nombre_individuo, Individuo& ind) {
    mpoblacion.insert(make_pair<string,Individuo> (nombre_individuo, ind));
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

bool Poblacion::existe(string nombre_individuo) {
    map<string, Individuo>:: iterator it = mpoblacion.begin();
    while (it != mpoblacion.end()) {
        if ((*it).first == nombre_individuo) return true;
        ++it;
    }
    return false;
}

Individuo Poblacion::buscar_individuo(string nombre_individuo) {
    map<string, Individuo>:: iterator it = mpoblacion.begin();
    while (it != mpoblacion.end()) {
        if ((*it).first == nombre_individuo) return (*it).second; 
        ++it;
    }
}
    
void Poblacion::reproduccion_sexual(Individuo& indpadre, string nombre_padre, Individuo& indmadre, string nombre_madre, string nombre_hijo, int l0) {
    Individuo indhijo;
    indhijo.anadir_padres(nombre_padre, nombre_madre);
    indhijo.reproducir_padres(indpadre, indmadre, l0);
    anadir_individuo(nombre_hijo, indhijo);
}

bool Poblacion::son_hermanos(string nombre_padre, string nombre_madre) {
    Individuo indpadre = buscar_individuo(nombre_padre);
    Individuo indmadre = buscar_individuo(nombre_madre);
    if (indpadre.tiene_madre().first == true and indmadre.tiene_madre().first == true) {
        if (indpadre.tiene_madre().second == indmadre.tiene_madre().second or indpadre.tiene_padre().second == indmadre.tiene_padre().second) return true;
    }
    return false;
}

bool Poblacion::son_antecesores(string n1, string n2) {
    Individuo ind = buscar_individuo(n2); 
    if (ind.tiene_madre().first == false) return false;
    else if (ind.tiene_madre().second == n1 or ind.tiene_padre().second == n1) return true;
    else {
        return (son_antecesores(n1, ind.tiene_madre().second) or son_antecesores(n1, ind.tiene_padre().second));
    }
}

void Poblacion::escribir_arbol_genealogico(string nombre_individuo) {
    int n = 1;
    Individuo ind = buscar_individuo(nombre_individuo);
    Individuo ind2 = buscar_individuo(nombre_individuo);
    cout << "  Nivel 0: " << nombre_individuo << endl; 
    bool primer = true;
    while (ind.tiene_madre().first or ind2.tiene_madre().first) {
        cout << "  Nivel " << n << ":";
        if (primer) {
            cout << " " << ind.tiene_padre().second;
            cout << " " << ind.tiene_madre().second;
            primer = false;
        }
        else {
            if (ind.tiene_madre().first) {
                cout << " " << ind.tiene_padre().second;
                cout << " " << ind.tiene_madre().second;
            }
            if (ind2.tiene_madre().first) {
                cout << " " << ind2.tiene_padre().second;
                cout << " " << ind2.tiene_madre().second;
            }
        }
        string nombre_madre = ind.tiene_madre().second;
        string nombre_padre = ind.tiene_padre().second;
        ind = buscar_individuo(nombre_padre);
        ind2 = buscar_individuo(nombre_madre);
        ++n;
        cout << endl;
    }
}

bool Poblacion::completar_arbol_genealogico() {
    vector<string> parcial;
    vector<string> completo;
    string nombre_individuo, nombre_madre, nombre_padre;
    for (int i = 0; i < parcial.size(); ++i) {
        cin >> parcial[i];
        nombre_individuo = parcial[i];
        Individuo ind = buscar_individuo(nombre_individuo);
        nombre_padre = ind.tiene_padre().second;
        nombre_madre = ind.tiene_madre().second;
        if (nombre_padre != 
    }
    