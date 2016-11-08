//
//  meseta.cpp
//
//
//  Created by Pablo Blanco Peris on 28/10/16.
//
//

#include <stdio.h>

#include <iostream>
using namespace std;

bool resuelve();

void meseta(int v[], int n, int &a, int &b);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    while(resuelve()){
        ;
    }
    
    
    return 0;
}
bool resuelve(){
    int n;
    cin >> n;
    int v[1000000];
    
    if(n <= 0){
        return false;
        
    }
    
    int j;
    for(int i = 0; i < n; i++){
        cin >> j;
        v[i] = j;
    }
    
    int k = 0, l = 0;
    meseta(v,n,k,l);
    cout << k << " " << l << endl;
    
    
    return true;
    
}

void meseta(int v[], int n, int &i, int &j){
    int mes = 0, mesMayor = 0;
    int a = 0, b = 0;
    
    if (n > 0){
        while(b < n){
            
            if(v[a] == v[b]){
                if(mes > mesMayor){
                    i = a;
                    j = b;
                    mesMayor = mes;
                }
                b++;
                mes++;
            }
            else{
                a = b;
                b++;
                mes = 1;
            }
            
        }
        
    }
    
    
}