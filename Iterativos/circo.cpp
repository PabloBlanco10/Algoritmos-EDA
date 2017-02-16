//
//  circo.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;

int circo(int v[], int n){
    int childs = 1;
    int max = v[0];
    bool encontrado = true;
    
    for(int i = 1; i < n; i++){
        if(encontrado){
            if(v[i] <= max){
                childs++;
            }
            else if(i < n - 1){
                if(v[i+1] <= v[i]){
                    childs++;
                    max = v[i];
                }
                else
                    encontrado = false;
            }
        }
    }
    
    return childs;
}



bool resuelve(){
    
    int n;
    cin >> n;
    int v[500000];
    
    while(n >0){
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i] = a;
        }
        cout << circo(v, n) << endl;
        cin >> n;
    }
    
    return false;
}

int main(){
    while(resuelve());
    return 0;
}