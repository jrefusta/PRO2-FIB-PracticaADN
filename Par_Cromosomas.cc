#include "Par_Cromosomas.hh"

Par_Cromosomas::Par_Cromosomas() {}

void Par_Cromosomas::leer_cromosomas_sex(int lx, int ly, char composicion_genetica) {
    c1 = vector<int>(lx);
    for (int i = 0; i < lx; ++i) {
        cin >> c1[i];
    }
    if (composicion_genetica == 'X') {
         c2 = vector<int>(lx);
        for (int i = 0; i < lx; ++i) {
            cin >> c2[i];
        }
    }
    else if (composicion_genetica == 'Y') {
         c2 = vector<int>(ly);
        for (int i = 0; i < ly; ++i) {
            cin >> c2[i];
        }
    }
}

void Par_Cromosomas::anadir_cromosomas_nor(int num_genes) {
    c1 = vector<int>(num_genes);
    c2 = vector<int>(num_genes); 
    for (int i = 0; i < num_genes; ++i) {
        cin >> c1[i];
    }
    for (int i = 0; i < num_genes; ++i) {
        cin >> c2[i];
    }
}

void Par_Cromosomas::escribir_cromosomas_sex(char c) {
    cout << "  X:";
    for (int i = 0; i < c1.size(); ++i) {
        cout << " " << c1[i];
    }
    
    cout << endl << "  Y:";
    if (c == 'X') {
        for (int i = 0; i < c2.size(); ++i) {
            cout << " " << c2[i];
        }
    }
    else if (c == 'Y') {
        for (int i = 0; i < c2.size(); ++i) {
            cout << " " << c2[i];
        }
    }
    cout << endl;
}

void Par_Cromosomas::escribir_cromosomas_nor(int i) {
        for (int j = 1 ; j <= 2; ++j) {
            cout << "  " << i << '.' << j << ":";
            if (j == 1) {
                for (int p = 0; p < c1.size(); ++p) {
                    cout << ' ' << c1[p];
                }
            }
            else {
                for (int h = 0; h < c2.size(); ++h) {
                    cout << ' ' << c2[h];
                }
            }
            cout << endl;
        }
}

void Par_Cromosomas::cruzar_normal(Par_Cromosomas& padre, Par_Cromosomas& madre) {
    int k, crom_pad, crom_mad;
    cin >> crom_mad >> crom_pad >> k;
    if (crom_mad == 0 and crom_pad == 0) {
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c1[i]);
            c2.push_back(padre.c1[i]);
        }
        for(int i = k; i < padre.c1.size(); ++i) {
            c1.push_back(padre.c1[i]);
            c2.push_back(madre.c1[i]);
        }
     
    }
    else if (crom_mad == 0 and crom_pad == 1) {
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c1[i]);
            c2.push_back(padre.c2[i]);
        }
        for(int i = k; i < padre.c1.size(); ++i) {
            c1.push_back(padre.c2[i]);
            c2.push_back(madre.c1[i]);
        }
    }
    else if (crom_mad == 1 and crom_pad == 0) {
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c2[i]);
            c2.push_back(padre.c1[i]);
        }
        for(int i = k; i < padre.c1.size(); ++i) {
            c1.push_back(padre.c1[i]);
            c2.push_back(madre.c2[i]);
        }
    }
    else if(crom_mad == 1 and crom_pad == 1) {
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c2[i]);
            c2.push_back(padre.c2[i]);
        }
        for(int i = k; i < padre.c1.size(); ++i) {
            c1.push_back(padre.c2[i]);
            c2.push_back(madre.c2[i]);
        }
    }
}       
void Par_Cromosomas::cruzar_sexual(Par_Cromosomas& padre, Par_Cromosomas& madre, int l0, char& composicion_genetica) {
    int k, crom_pad, crom_mad;
    cin >> crom_mad >> crom_pad >> k;   
    cout << "mad " << crom_mad << " pad " << crom_pad << " k " << k << endl;
    if (crom_mad == 0 and crom_pad == 0) {
        composicion_genetica = 'X';
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c1[i]);
            c2.push_back(padre.c1[i]);
        }
        for(int i = k; i < l0; ++i) {
            c1.push_back(padre.c1[i]);
            c2.push_back(madre.c1[i]);
        }
        for(int i = l0; i < madre.c1.size(); ++i) {
            c1.push_back(madre.c1[i]);
        }
        for(int i = l0; i < padre.c1.size(); ++i) {
            c2.push_back(padre.c1[i]);
        }
    }
    else if (crom_mad == 0 and crom_pad == 1) {
        composicion_genetica = 'Y';  
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c1[i]);
            c2.push_back(padre.c2[i]);
        }
        for(int i = k; i < l0; ++i) {
            c1.push_back(padre.c2[i]);
            c2.push_back(madre.c1[i]);
        }
        for(int i = l0; i < madre.c1.size(); ++i) {
            c1.push_back(madre.c1[i]); 
        }
        for(int i = l0; i < padre.c2.size(); ++i) {
            c2.push_back(padre.c2[i]);
        }
    }
    else if (crom_mad == 1 and crom_pad == 0) {
        composicion_genetica = 'X';       
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c2[i]);
            c2.push_back(padre.c1[i]);
        }
        for(int i = k; i < l0; ++i) {
            c1.push_back(padre.c1[i]);
            c2.push_back(madre.c2[i]);
        }
        for(int i = l0; i < madre.c2.size(); ++i) {            

            c1.push_back(madre.c2[i]);
        }
        for(int i = l0; i < padre.c1.size(); ++i) {
            c2.push_back(padre.c1[i]);
        }
    }
    else if(crom_mad == 1 and crom_pad == 1) {
        composicion_genetica = 'Y';  
        for(int i = 0; i < k; ++i) {
            c1.push_back(madre.c2[i]);
            c2.push_back(padre.c2[i]);
        }
        for(int i = k; i < l0; ++i) {
            c1.push_back(padre.c2[i]);
            c2.push_back(madre.c2[i]);
        }
        for(int i = l0; i < madre.c2.size(); ++i) {
            c1.push_back(madre.c2[i]);
        }
        for(int i = l0; i < padre.c2.size(); ++i) {
            c2.push_back(padre.c2[i]);
        }
    }
}