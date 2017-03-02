//
//  cine.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//
#include <stdio.h>
#include <iostream>

using namespace std;


void cine(int v[], int n){
    int r = 0;
    bool impar = false;
    bool ok = true;
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            r++;
            if(impar){
                ok = false;
            }
        }
        else{
            impar = true;
        }
    }
    if(ok)
        cout << "SI " << r << endl;
    else
        cout << "NO" << endl;
}


bool resuelve(){
    int casos, n;
    int v[100000];
    
    cin >> casos;
    
    while(casos > 0){
        cin >> n;
        
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            v[i] = a;
        }
        
        cine(v,n);
        casos--;
    }
    return false;
}
int main(){
    while(resuelve());
    return 0;
}