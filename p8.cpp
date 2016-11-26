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


// P = { 0 <= a <= long(v) ^ 0 <= b < long(v) ^ b >= a - 1 ^
// para todo x: a - 1 <= x <=


int picos(int v[], int a, int b, int n){
    int r;
    int m = (a + b) / 2;
    if(a==b)
        return a;
    else if(v[m] < v[m+1])
        r = picos(v,m+1,b,n);
    else
        r = picos(v,a,m,n);
    
    return r;
    
    
    
    
    
    
//    int r;
//    int m = (a + b) / 2;
//   
//    if((a == b) && (a == 0))
//        r = 0;
//    else if((a == b) && (a == n-1))
//        r = a;
//    
//    else if(a>b){
//        
//        if(v[a] > v[b]){
//            r = a;
//        }
//        else r = b;
//        
//    }
//    
//    else if((v[m] > v[m-1]) && (v[m] > v[m+1]) && (a>0) && (b < n)){
//        r = m;
//    }
//    
//    else if(v[m] < v[m+1]){
//        r = picos(v, m+1, b, n);
//    }
//    else{
//        r = picos(v, a, m, n);
//    }
//    
//    
//    return r;
    
}


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
        
        cout <<  picos(v, 0, n-1, n) << endl;
        cin >> n;
    }
    return false;
}

int main(){
    
    while(resuelve());
    return 0;
}