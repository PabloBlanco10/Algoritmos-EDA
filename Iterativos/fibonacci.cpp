//
//  fibonacci.cpp
//  
//
//  Created by Pablo Blanco Peris on 31/1/17.
//
//

#include <stdio.h>
#include <iostream>

using namespace std;


int fibonacci(int n, int a, int b){
    int suma;
    if(n == 0)
        suma = a;
    else if(n == 1)
        suma = b;
    else{
        for(int i = 2; i <= n; i++){
            suma = a + b;
            a = b;
            b = suma;
        }
    }

    return suma;
    
}

bool resuelve(){
    
    int n, a, b;
    cin >> n;
    cin >> a;
    cin >> b;
    
    while((n != 0) || (a != 0) || (b != 0)){
        
        cout << fibonacci(n, a, b) << endl;
        cin >> n;
        cin >> a;
        cin >> b;
    }
    
    
    return false;
}


int main(){
    while(resuelve());
    return 0;
}