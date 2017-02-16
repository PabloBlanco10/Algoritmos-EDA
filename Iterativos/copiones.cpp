//
//  copiones.cpp
//  
//
//  Created by Pablo Blanco Peris on 30/1/17.
//
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;


//void copiones2(int v[], int n, int m, int &copiados, int &detectados){
//    int cambiado = 0;
//    for(int i = 0; i < n; i++){
//        
//        for(int j = i+1; j < n; j++){
//            if(v[i] == v[j]){
//                copiados++;
//                if((j - i) <= m)
//                    detectados++;
//                int aux;
//                aux = v[i+1+cambiado];
//                v[i+1+cambiado] = v[j];
//                v[j] = aux;
//                cambiado++;
//            }
//        }
//        if(cambiado != 0)
//            i += cambiado - 1;
//        cambiado = 0;
//    }
//}




//void copiones(int v[], int n, int m, bool marcasCopiados[], bool marcasDetectados[] int &copiados, int &detectados){
//    
//    for(int i = 0; i < n; i++){
//        for(int j = i-1; ((j >= 0) && ((i - j) <= m)); j--){
//            if((v[i] == v[j]) && (!marcas[i])){
//                detectados++;
//                marcas[i] = true;
//            }
//        }
//    }
//    
//    //ordenamos y recorremos una vez
//    // sort(v, v + n);
//    for(int i = 1; i < n; i++){
//        for(int j = i; j < n; j++){
//            if((v[j] == v[i]) && (!marcas2[i])){
//                copiados++;
//                marcas2[i] = true;
//            }
//        }
//        //        if(v[i] == v[i-1])
//        //            copiados++;
//    }
//}
//

void copiones3(int v[], int n, int m, bool marcasCopiados[], bool marcasDetectados[], int &copiados, int &detectados){
    
    for(int i = 0; i < n; i++){
        
        for(int j = i+1; j < n; j++){
            
            if((v[j] == v[i]) && (!marcasCopiados[j])){
                copiados++;
                marcasCopiados[j] = true;
            }
            if((v[i] == v[j]) && ((j - i) <= m) && (!marcasDetectados[j])){
                detectados++;
                marcasDetectados[j] = true;
            }
        }
    }
    
    
}
bool resuelve(){
    int n, m, copiados = 0, detectados = 0;
    int v[10000];
    bool marcasCopiados[10000];
    bool marcasDetectados[10000];
    
    
    //numero de examenes
    cin >> n;
    //numero de examenes que recuerda
    cin >> m;

    
    while (n > 0) {
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i] = a;
            marcasDetectados[i] = false;
            marcasCopiados[i] = false;
        }
       // clock_t start = clock();
        copiones3(v, n, m, marcasCopiados, marcasDetectados, copiados, detectados);
        cout << copiados << " " << detectados << endl;
        //printf("Tiempo transcurrido: %f \n", ((double)clock() - start) / CLOCKS_PER_SEC);
        copiados = 0;
        detectados = 0;
        cin >> n;
        cin >> m;
    }
    return false;
}


int main(){
    while(resuelve());
    return 0;
}
