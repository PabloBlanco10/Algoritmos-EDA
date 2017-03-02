//
//  p8.cpp
//
//
//  Created by Pablo Blanco Peris on 25/11/16.
//
//

#include <stdio.h>

#include <iostream>
using namespace std;

// P = { 0 <= a <= long(v) < n ^ 0 <= b < long(v) < n ^ b >= a - 1 ^
// para todo x: a - 1 <= x <= b v[a] < v[x] ^ v[x] > v[b] ^

int picos(int v[], int a, int b){
    int r;
    int m = (a + b) / 2;
    if(a==b)
        return a;
    else if(v[m] < v[m+1])
        r = picos(v,m+1,b);
    else
        r = picos(v,a,m);
    
    return r;
    
}
// Q = { r = max i: 0 <= i < n: v[i] }


bool resuelve(){
    int n;
    cin >> n;
    int v[100000];
    int aux;


    
    
    while(n>0){
        for(int j = 0; j < n; j++){
            cin >> aux;
            v[j] = aux;
        }
        
        cout <<  picos(v, 0, n-1) << endl;
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}