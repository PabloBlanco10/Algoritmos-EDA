//
//  recursivos.cpp
//  
//
//  Created by Pablo Blanco Peris on 30/1/17.
//
//

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int decimalToBinary(int n){
    int r;
    
    if(n < 2)
        r = n;
    else{
        int digito = n%2;
        r = 10*decimalToBinary(n/2) + digito;
    }
    
    return r;
}

int binaryToDecimal(int n){
    
    int r;
    
    if(n < 2)
        r = n;
    else{
        int digito = n % 10;
        r = 2*binaryToDecimal(n/10) + digito;
    }
    
    return r;
}

void ejercicio1(int v[], int n, int i, int &distMejor, int &primero, int &segundo){
    int dist;
    
    if(i < n - 1){
        dist = v[i+1] - v[i];
        if(dist < distMejor){
            distMejor = dist;
            primero = v[i];
            segundo = v[i+1];
        }
        ejercicio1(v, n, i+1, distMejor, primero, segundo);
    }
}

int complementario(int n){
    int r;
    
    if(n < 9)
        r = 9 - n;
    else{
        int digito = n%10;
        r = 10 * complementario(n/10) + (9 - digito);
    }
    
    return r;
}

int hostal(int v[], int a, int b){
    int r;

    if(a+1 < b)
        r = (v[a] + v[b]) + 2 * hostal(v, a+1, b-1);
    else
        r = v[a] + v[b];
    
    
    return r;
}

//existe algun v[i] = i
bool dieciseis(int v[], int a, int b){
    bool r = false;
    int m = (a+b)/2;
    
    if(a > b)
        r = false;

    else {
        if(v[m] == m)
            r = true;
        else if(v[m] > m){
            //vamos hacia el principio
            r = dieciseis(v, a, m-1);
        }
        else if(v[m] < m){
            //vamos hacia el final
            r = dieciseis(v, m+1, b);
        }
    }
    return r;
}

int resuelve(){
    int n, primero, segundo, distMejor = 100;
    cin >> n;
    while(n!=0){
        int v[1000];
        int a;
//        for(int i = 0; i < n; i++){
//            cin >> a;
//            v[i] = a;
//        }
//        
//////        if(dieciseis(v,0, n))
//////            cout << "SI" << endl;
//////        else
//////            cout << "NO" << endl;
////        cout << hostal(v, 0, n-1) << endl;
////        cout << complementario(n) << endl;
//        distMejor = 100;
//        ejercicio1(v, n, 0, distMejor, primero, segundo);
//        cout << "Primero: " << primero << endl;
//        cout << "Segundo: " << segundo << endl;
        cout << decimalToBinary(n) << endl;
        cin >> n;

    }
    return false;
}

int main(){
    
    while (resuelve());
    return 0;
    
}