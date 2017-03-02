//
//  loteria.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;


int loteria(int v[], int n){
    int r = 0;
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0)
            r++;
    }
    
    return r;
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
        
        cout << loteria(v,n) << endl;
        casos--;
    }
    return false;
}
int main(){
    while(resuelve());
    return 0;
}