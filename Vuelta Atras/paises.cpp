//
//  paises.cpp
//  
//
//  Created by Pablo Blanco Peris on 13/1/17.
//
//

#include <iostream>
#include <climits>

using namespace std;


const int MP = 20; // Num max de paises
const int MC = 20; // Num max de colores



bool esValida(int sol[], int k, bool fronteras[MP][MP]){
    bool ok = true;
    
    for(int i = 0; (i < k) && ok; i++){
        if((fronteras[k][i]) && (sol[k] == sol[i]))
            ok = false;
    }
    
    return ok;
}

void colorearMapa(int k, int sol[], int npaises, int ncolores, int paises[], int colores[], bool fronteras[MP][MP], int coste, int &mejorcoste){

    for(int i = 0; i < ncolores; i++){
        sol[k] = i;
        if(esValida(sol, k, fronteras)){
            coste += paises[k] * colores[i];
            if(k == npaises-1){
                if(coste < mejorcoste){
                    mejorcoste = coste;
                }
            }
            else{
                colorearMapa(k+1, sol, npaises, ncolores, paises, colores, fronteras, coste, mejorcoste);
                coste -= paises[k] * colores[i];
            }
        }
    }
    
}


int main() {
    int nmapas;    // num de mapas a colorear
    
    int npaises;   // num de paises del mapa actual
    int ncolores;  // num de colores para el mapa actual
    
    int paises[MP];  // superficie de cada pais en el mapa actual
    int colores[MC]; // coste para colorear una unidad de superficie usando cada color
    
    // fronteras[i][j] indica si existe frontera entre los paises i y j en el mapa
    // Es una matriz simetrica (fronteras[i][j] == fronteras[j][i])
    bool fronteras[MP][MP];
    int sol[MP];
    
    // Leer numero de mapas del caso de pruebas
    cin >> nmapas;
    for (int i=0; i<nmapas; i++) {
        // Leer numero de paises y colores para el mapa actual
        cin >> npaises;
        cin >> ncolores;
        
        // Leer superficie de cada pais
        for (int j=0; j<npaises; j++)
            cin >> paises[j];
        
        // Leer coste de cada color (por unidad de superficie)
        for (int j=0; j<ncolores; j++)
            cin >> colores[j];
        
        // Leer matriz de fronteras
        for (int j=0; j<npaises; j++) {
            for (int k=0; k<npaises; k++) {
                cin >> fronteras[j][k];
            }
        }
        
        int mejorcoste = INT_MAX;
        int coste = 0;
        int k = 0;
        
        /* Llama aquí a tu procedimiento y calcula el valor de mejorcoste */
        /* .... */
        colorearMapa(k, sol, npaises, ncolores, paises, colores, fronteras, coste, mejorcoste);

        cout << mejorcoste << endl;
    }
    
    return 0;
}