//
//  divideyvenceras.cpp
//  
//
//  Created by Pablo Blanco Peris on 30/11/16.
//
//

#include <stdio.h>


//algoritmo que diga que habria en v[3] si estuviera ordenado
//ordenar y mirar v[3] seria O(n log n)
// pero por particion :
// particion O(n)
// T(n) =
//            - caso base si n = 1
//            - T(n/2) + c * n si n > 1
//por tanto pertenece al O (n)
//
//caso peor que coja un mal pivote,
//pero el mejor caso seria la mediana del vector para que partiera bien
//se calculan todas las medianas y luego la mediana de las medianas
//se hace una llamada a particion(v,n,mm,p)
//se empeoran todos los casos para mejorar el caso peor y asegurar un coste del caso peor



//ejercicio del campeonato de equipos
//cualquier algoritmo va a ser minimo cuadratico porque va a ser n^2 / 2 solo para escribir el resultado



//ejercicio del pico de la montaña
//    T(n):
//    caso base si n = 2
//    2 T (n/2) + n + n si n > 2
//    O(n log n)



// ejercicio 18 bolas que pesan diferente
// 1 bola que pesa diferente, se van haciendo grupos de 3 y el que pesa diferente es donde esta la bola

//si n == 2 entonces devuelve la más pesada
//si n == 1 entonces devuelve esa bola
//
//sino si peso(a) > peso(b) resuelve(a)
//sino si peso(a) < peso(b) resuelve(b)
//sino si son iguales return c;


struct Bola{
    int ID;
    float peso;
};

int balanza(Bola[] bolas, int a, int b, int a2, int b2);
// - 1 primer trozo pesa mas
// + 1 si el segundo
// 0 iguales



int resuelve(Bola[] bolas, int a, int b){
    
    if(b - (a+1) == 1){
        return bolas[a].ID;
    }
    else if(b - (a+1) == 2){
        int r = balanza(bolas,a,a,b,b);
        if(r == - 1)
            return bolas[a].ID;
        else//r==1
            return bolas[b].ID;
    }
    else{
        int m = (a + b) / 2;
        
        if((b-a+1) % 2 == 0){//par
            
            int r = balanza(bolas, a, m-1, m, b);
            if(r == -1){
                return resuelve(bolas, a, m-1);
            }
            else if(r == 1){
                return resuelve(bolas,m,b);
            }
            
        }
        else{//impar
            
            int r = balanza(bolas,a,m-1,m,b-1);
            if(r==-1)
                return resuelve(bolas,a,m-1);
            else if(r == 1)
                return resuelve(bolas, m, b - 1);
            else//r==0
                return bolas[b].ID;
        }
    }
    
    
}

int resuelve(Bola[] bolas, int n){
    return resuelve(bolas, 0, n-1);
}



































