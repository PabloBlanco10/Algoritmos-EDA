//
//  p7.cpp
//  
//
//  Created by Pablo Blanco Peris on 18/11/16.
//
//

#include <stdio.h>
#include <iostream>
using namespace std;


bool evaluaExpresion(int a, int b, int c, int d, bool &ret, int &p1, int &p2){
    bool r;
    int e, f, g, h;
    if((a != 0) && (b != 0) && (c != 0) && (d != 0)){
        if ((a*b) != (c*d)){
            ret = false;
            return false;
        }
        else {
            p1 = a;
            p2 = c;
        }
       // r = ((a*b) == (c*d));
//        cout << "ninguno es cero" << endl;
    }
    else{
    
        if(a == 0){
            cin >> e;
            cin >> f;
            cin >> g;
            cin >> h;
            p1 = e + g;
            evaluaExpresion(e,f,g,h, ret, p1, p2);
           // peso1 += e + g;
           // cout << "peso1 = " << peso1 << endl;
        }
        if(b == 0){
            cin >> e;
            cin >> f;
            cin >> g;
            cin >> h;
            evaluaExpresion(e,f,g,h, ret, p1, p2);
        }
        if(c == 0){
            cin >> e;
            cin >> f;
            cin >> g;
            cin >> h;
            p2 = e + g;
            evaluaExpresion(e,f,g,h, ret, p1, p2);
            //peso1 += e + g;
           // cout << "peso2 = " << peso2 << endl;
        }
        //else peso2 += c;
        
        if(d == 0){
            cin >> e;
            cin >> f;
            cin >> g;
            cin >> h;
            evaluaExpresion(e,f,g,h, ret, p1, p2);
        }
    }
    
    if ((a*b) != (c*d))
        ret = false;
    if ((e*f) != (g*h))
        ret = false;
    p1 = p1 * b;
    p2 = p2 * d;
//    if((p1) != (p2))
//        ret = false;
    
    
    cout << "peso 1 final: "  << p1 << endl;
    cout << "peso 2 final: "  << p2 << endl;

    r = ret;
    return r;
}

void resuelve(int a, int b, int c, int d){
    bool si = false;
    bool p = true;
    int p1 = 0;
    if (evaluaExpresion(a,b,c,d,p,p1,p1))
        cout << "SI" << endl;
    
    else
        cout << "NO" << endl;
//    cout << evaluaExpresion(a, b, c, d) << endl;
//    cout << "resuelve hecho" << endl;
}

int main(){
    int a, b, c, d;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    bool ceros = true;

    while(ceros){
        
        resuelve(a,b,c,d);
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;
        if ((a == 0) && (b == 0) && (c == 0) && (d == 0)) {
            ceros = false;
        }
//        cout << " si entra al while" << endl;
    }
    
    return 0;
    
}






////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//////////// HECHO EN CLASE

void movilEquilibrado(int pi, int di, int pd, int dd,
                      int &peso, bool &equilibrado){
    
    int pi2, di2, pd2, dd2;
    bool equilIz = true, equilDr = true;
    
    if(pi == 0){
        cin >> pi2 >> di2 >> pd2 >> dd2;
        movilEquilibrado(pi2, di2, pd2, dd2, pi, equilIz);
    }
    
    
    if(pd == 0){
        cin >> pi2 >> di2 >> pd2 >> dd2;
        movilEquilibrado(pi2, di2, pd2, dd2, pd, equilDr);
    }
    
    peso = pi + pd;
    equilibrado = equilIz && equilDr && (pi * di == pd * dd)
    
    
}





//si pi != 0 y pd != 0 caso base
// actualizar peso (pi + pd)
// decir si esta equilibrado
// si no
// llamada recursiva movil izq
// llamada recursiva movil dcho
// actualizar peso
// decir si esta equilibrado

//
//if((pi != 0) && (pd != 0)){
//    peso = pi + pd;
//    equilibrado = pi * di == pd * dd);
//}
//else{
//    int pi2, di2, pd2, dd2;
//    int pesoIz;
//    bool equilIz;
//    
//    if(pi == 0){
//        cin >> pi2 >> di2 >> pd2 >> dd2;
//        movilEquilibrado(pi2, di2, pd2, dd2, pesoIz, equilIz);
//    }
//    else {
//        pesoIz = pi;
//        equilIz = true;
//    }
//}
//
//int pesoDr;
//bool equilDr;
//
//
//if(pd == 0){
//    cin >> pi2 >> di2 >> pd2 >> dd2;
//    movilEquilibrado(pi2, di2, pd2, dd2, pesoDr, equilDr);
//}
//else {
//    pesoDr = pd;
//    equilDr = true;
//}
//peso = pesoIz + pesoDr;
//equilibrado = equilIz && equilDr && (pesoIz * di == pesoDr * dd)







bool resuelve(){
    int pi, di, pd, dd;
    cin >> pi >> di >> pd >> dd;
    if((pi == 0) && (di == 0) && (pd == 0) && (dd == 0))
        return false;
    
    int peso;
    bool equilibrado;
    movilEquilibrado(pi, pd, dd, peso, equilibrado);
    if(equilibrado)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}



int main(){
    while(resuelve())
        ;
    return 0;
}



















