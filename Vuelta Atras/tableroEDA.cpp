//
//  tableroEDA.cpp
//  
//
//  Created by Pablo Blanco Peris on 8/2/17.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;

const int Alto = 5;
const int Ancho = 8;





void desmover(int i, int &cact, int &fact){
    
    switch(i){
        case 0:
            cact--;
            break;
        case 1:
            fact++;
            break;
        case 2:
            cact++;
            break;
        case 3:
            fact--;
            break;
        default:
            break;
    }
    
}



bool esValida(char &ultimaLetra, char tablero[Ancho][Alto], int fact, int cact){
    //para que sea valida tiene que estar dentro del tablero, y que la letra encontrada sea la correcta
    
    bool ok = false;
    
    if(ultimaLetra == 'E'){
        if(tablero[fact][cact] == 'D')
            ok = true;
        
    }
    else if(ultimaLetra == 'D'){
        if(tablero[fact][cact] == 'A')
            ok = true;
    }
    else if(ultimaLetra == 'A'){
        if(tablero[fact][cact] == 'E')
            ok = true;
    }
    
    if(ok)
        ultimaLetra = tablero[fact][cact];
    
    return ok;
}


void tratarSolucion(int sol[], int k){
    
    cout << "SOLUCIÓN ENCONTRADA: ";
    for(int i = 0; i <  k; i++){
        
        if(sol[i] == 0)
            cout << "E, ";
        else if(sol[i] == 1)
            cout << "N, ";
        else if(sol[i] == 2)
            cout << "W, ";
        else if(sol[i] == 3)
            cout << "S, ";
    }
    
    if(sol[k] == 0)
        cout << "E ";
    else if(sol[k] == 1)
        cout << "N ";
    else if(sol[k] == 2)
        cout << "W ";
    else if(sol[k] == 3)
        cout << "S ";
    
    
    cout << endl;
}


void mover(int i, int &cact, int &fact, bool &dentro){
    dentro = true;
    
    switch(i){
        case 0:
            cact++;
            if(cact >= Ancho){
                dentro = false;
            }
            break;
        case 1:
            fact--;
            if(fact < 0){
                dentro = false;
            }
            break;
        case 2:
            cact--;
            if(cact < 0){
                dentro = false;
            }
            break;
        case 3:
            fact++;
            if(fact >= Ancho){
                dentro = false;
            }
            break;
        default:
            break;
    }
    
}

void tableroEDA(int k, int sol[], int fact, int cact, int ffinal, int cfinal, int solMejor[], char tablero[Ancho][Alto], char ultimaLetra){
    
    for(int i = 0; i < 4 ; i++){
        sol[k] = i;
        bool dentro;
        mover(i, fact, cact, dentro);
        if((dentro) && (esValida(ultimaLetra, tablero, fact, cact))){
            if((fact == ffinal) && (cact == cfinal)){
                tratarSolucion(sol, k);
            }
            else{
                tableroEDA(k+1, sol, fact, cact, ffinal, cfinal, solMejor, tablero, ultimaLetra);
            }
        }
        desmover(i, fact, cact);
        ultimaLetra = tablero[fact][cact];
    }
}


int main() {
    
    char Tablero[Ancho][Alto];
    
    Tablero[0][0] = 'M';
    Tablero[0][1] = 'A';
    Tablero[0][2] = 'D';
    Tablero[0][3] = 'E';
    Tablero[0][4] = 'E';
    Tablero[1][0] = 'D';
    Tablero[1][1] = 'E';
    Tablero[1][2] = 'B';
    Tablero[1][3] = 'A';
    Tablero[1][4] = 'D';
    Tablero[2][0] = 'A';
    Tablero[2][1] = 'E';
    Tablero[2][2] = 'D';
    Tablero[2][3] = 'E';
    Tablero[2][4] = 'M';
    Tablero[3][0] = 'A';
    Tablero[3][1] = 'D';
    Tablero[3][2] = 'X';
    Tablero[3][3] = 'D';
    Tablero[3][4] = 'P';
    Tablero[4][0] = 'E';
    Tablero[4][1] = 'D';
    Tablero[4][2] = 'E';
    Tablero[4][3] = 'A';
    Tablero[4][4] = 'L';
    Tablero[5][0] = 'E';
    Tablero[5][1] = 'A';
    Tablero[5][2] = 'D';
    Tablero[5][3] = 'R';
    Tablero[5][4] = 'E';
    Tablero[6][0] = 'D';
    Tablero[6][1] = 'N';
    Tablero[6][2] = 'A';
    Tablero[6][3] = 'T';
    Tablero[6][4] = 'D';
    Tablero[7][0] = 'A';
    Tablero[7][1] = 'D';
    Tablero[7][2] = 'E';
    Tablero[7][3] = 'D';
    Tablero[7][4] = 'A';
    
    int sol[Ancho*Alto];
    int solMejor[Ancho*Alto];

    int fact = 0;
    int cact = 4;
    int ffinal = 7;
    int cfinal = 0;
    char ultimaLetra = 'E';
    
    tableroEDA(0, sol, fact, cact, ffinal, cfinal, solMejor, Tablero, ultimaLetra);
    
    
    return 0;
    
}