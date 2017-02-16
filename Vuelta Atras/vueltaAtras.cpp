//
//  vueltaAtras.cpp
//
//
//  Created by Pablo Blanco Peris on 14/12/16.
//
//

#include <stdio.h>

//llamada inicial : palabras(sol, 0)


void palabras(int sol[5], int k){
    
    for(int l = 0; l < 27; l++){
        sol[k] = l;
        
        if(k == 4)
            imprimir(sol);
        else
            palabras(sol, k + 1);
    }
    
    
}



//palabras n letras q no se repita ninguna letra

void palabras(int sol[], int n, int k){
    
    for(int l = 0; l < 27; l++){
        sol[k] = l;
        if(esValida(sol, k)) {
            
            if(k == 4)
                imprimir(sol);
            else
                palabras(sol, k + 1);
        }
    }
}

const int N = 7;

int main(){
    int sol[N*(N+1)/2 + 1];
    sol[0] = 6; sol[1] = 6;
    int k = 2;
    bool marcas[N][N] ;
    for(int i= 0; i < N; i++)
        for(int j=0; j < N; j++)
            marcas[i][j]=false;
    
    marcas[6][6] = true;
    domino(sol, k, marcas);
    
    return 0;
}

bool esValida(int sol[], int k, bool marcas[N][N]){
    return !marcas[sol[k-1]][sol[k]];
}

bool esSolucion(int sol[], int k){
    return ((k == N*(N+1)/2) && (sol[k] == sol[0]))
}



void domino(int sol[], int k, bool marcas[N][N]){
    
    for(int i = 0; i < N; i++){
        sol[k] = i;
        if(esValida(sol, k, marcas)){
            if(esSolucion(sol, k)){
                //imprimir
            }else{
                marcas[sol[k-1]][i] = true;
                marcas[i][sol[k-1]] = true;
                domino(sol, k + 1, marcas);
                marcas[sol[k-1]][i] = false;
                marcas[i][sol[k-1]] = false;
            }
        }
    }
}

void actualizarPosActual(int &fact, int &cact, int m, bool &dentro){
    dentro = true;
    switch (m) {
        case 0:
            if(fact > 0)
                fact--;
            else dentro = false;
            break;
            
    }
}



void laberinto(bool lab[N][N], int sol[], int k, bool visitadas[N][N], int fact, int cact, bool &salir){
    
    for(int m = 0; (m < 4) && !salir; m++){
        sol[k] = m;
        bool dentro;
        actualizarPosActual(fact, cact, m, dentro);
        if(dentro && laberinto[fact][cact] && !visitadas[fact][cact]){
           if((fact == N - 1) && (cact == N -1))){
              imprimir(sol, k);
              salir = true;
               //if solucion es mejor que solucion mejor cambio la solucion
           }else{
               visitadas[fact][cact] = true;
               laberinto(lab, sol, k+1, visitadas, fact, cact, salir);
               //visitadas[fact][cact] = false; no tiene sentido desmarcar si buscamos una solucion cualquiera.
           }
        }

    }
}

// el viajante: complejidad del problema es factorial, suponiendo que todas estan conectadas con todas.
// necesitamos un array doble para llevar las distancias, array de ciudades(N) como solucion y otro como
// solucion mejor que sea de longitud la suma de todas las longitudes
// las ciudades que no estén conectadas se pondrán con distancia = - 1

bool esValida(int sol[N], int k, bool visitadas[N], int distancias[N][N]){
    return !visitada[sol[k]] && distancias[sol[k-1][sol[k]]] > -1
}
bool esSolucion(int sol[N], int k, int distancias[N][N]){
    return ((k == N-1) && (distancias[sol[k]][sol[0]] > -1));
}

void viajante(int distancias[N][N], int sol[N], int k, int coste, bool visitadas[N], int mejorSol[N], int &costeMejor){
    
    for(int c = 0; c < N; c++){
        sol[k] = c;
        if(esValida(sol, k, visitadas, distancias)){
            coste += distancias[sol[k-1]][sol[k]];
            if(esSolucion(sol, k, distancias)){
                coste += distancias[sol[k]][sol[0]];
                if(coste < costeMejor){
                    copiarArray(sol, mejorSol);
                    costeMejor = coste;
                }
                coste -= distancias[sol[k]][sol[0]];
            }else{
                visitadas[sol[k]] = true;
                viajante(distancias, sol, k+1, coste, visitadas, mejorSol, costeMejor);
                visitadas[sol[k]] = false;
            }
            coste -= distancias[sol[k-1]][sol[k]];
        }
    }
}


//2,3, EXAMEN 7,8,9,10




//EJERCICIO DE LA MOCHILA
//
//calcular coef O(n) coef = V/P
//ordenar O(n log n)
//meterlos en mochila O(n)
//
//TODO EN ORDEN O (n log n)
//pero puede quedar espacio vacio en la mochila

void mochila(int p[], int v[], int n, int pesoMax, int k, bool sol[], int peso, int valor, bool mejorSol[], mejorValor){
    sol[k] = true;
    pes += p[k];
    valor += v[k];
    if(peso <= pesoMax){ //esValida
        if(k == n-1){ // esSolucion
            if(valor > mejorValor){ //es la mejor
                mejorValor = valor;
                copiarArray(sol, mejorSol, n);
            }
        }else{
            //if(valor + etimacionOptimista() > mejorValor
            mochila(p, v, n, pesoMax, k+1, sol, peso, valor, mejorSol, mejorValor);
        }
    }//esValida
    //no meter el objeto
    sol[k] = false;
    peso -= p[k];
    valor -= v[k];
    if(peso <= pesoMax){//esValida
        if(k == n-1){//esSolucion
            if(valor > mejorValor){//es la mejor
                mejorValor = valor;
                copiarArray(sol, mejorSol, n);
            }
        }else{
            //if(valor + etimacionOptimista() > mejorValor
            mochila(p, v, n, pesoMax, k+1, sol, peso, valor, mejorSol, mejorValor);
        }
    }
}





//ejercicio de los caballos

void movimiento(int x, int y, int m, int &nx, int &ny){
    int dx[] = {1, 2, ... }
    int dy[] = {-2, -1, ...}
    
    nx = x + dx[m];
    ny = y + dy[m];
    
}

void caballo (int n, int filaIni, int colIni, int fila, int col, int sol[N][N]); int k){
    for(int i = 0; i <= 7; i++){
        int nfila, ncol;
        movimiento(fila, col, i, nfila, ncol);
        if(esValida(nfila, ncol, sol, n)){
            sol[nfila][ncol] = k + 1; // metemos el numero de movimiento.
            if(esSolucion(sol, n, filaIni, colIni, nfila, ncol, k)){ //comprobar que k = n * (n - 1) y que se pueda acceder a la posicion inicial
                tratarSolucion();
            }else{
                caballo(n, filaIni, colIni, nfila, ncol, sol, k + 1);
            }
        }else{
            sol[nfila][ncol] = -1;
        }
    }
}

//ejercicio 9 TIPICO EXAMEN

// M artistas y contratamos N (N <= M)
// B[i] = beneficio del artista i, puede ser positivo o negativo
// vetos[i][j] si hay veto de i a j
// solucion es un array de booleanos bool sol [M]

void concierto(bool vetos[M][M], bool sol[], int k, int b, int contratados, bool mejorSol[], int mb){
    sol[k] = false;
    if(
}

























