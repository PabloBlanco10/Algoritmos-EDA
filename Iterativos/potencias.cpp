//
//  potencias.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;

int potencias(int a, int b){
    int r;
    if(b == 0){
        r = 1;
    }
    else if (b == 1){
        r = a;
    }
    else{
        int pot = a;
        for(int i = 0; i < b; i++){
            r += pot;
            pot *= a;
        }
    }

    return (r + 1) % 1000007;
}



bool resuelve(){
    int a,b;
    cin >> a >> b ;
//    cin >> b ;
    
    while(a > 0){
        
        cout << potencias(a, b) << endl;
        cin >> a >> b ;
//        cin >> b ;
    }
    
    
    return false;
}

int main(){
    while(resuelve());
    return 0;
}