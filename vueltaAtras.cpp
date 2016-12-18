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

































