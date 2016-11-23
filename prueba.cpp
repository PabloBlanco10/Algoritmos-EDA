
#include <iostream>
using namespace std;

bool resuelve();
int pares(int v[], int n);
int sumaBuenos(int v[], int n);
int picos(int v[], int n);
int miradores(int v[], int n);
bool gaspariforme(int v[], int n);
int credito(int v[], int n);
void inter(int v[], int n);
int moda(int v[], int n);
void meseta(int v[], int n, int &a, int &b);
int suma(int v[], int n);
int cuantas(int v[], int n, int suma);
int seisadecimal(int n);


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, j = 0, k;
    cin >> n;

    while(j < n){
        cin >> k;
        cout << seisadecimal(k) << endl;
    }
    
    
    return 0;
}

bool resuelve(){
        int v[10000];
    int n = 0;
    if(n <= 0){
        return false;
        
    }
    
    int j;
    for(int i = 0; i < n; i++){
        cin >> j;
        v[i] = j;
    }
    //    int s = suma(v,n);
    //    cout << cuantas (v,n,suma) << '\n';
    //cout << pares(v, n) << endl;
    //cout << sumaBuenos(v, n) << endl;
    //cout << picos(v, n) << endl;
    //cout << miradores(v, n) << endl;
    //cout << gaspariforme(v, n) << endl;
    //cout << credito(v, n) << endl;
    //		//inter(v,n);
    //    int k = 0, l = 0;
    //    meseta(v,n,k,l);
    //    cout << k << " " << l << endl;
   // cout << seisadecimal << endl;
    
    
    return true;
    
}


int numVecesP(int v[], int i, int n){
    int r;
    if(i == n) //vacio
        r = 0;
    else{
        int s = numVecesP(v, i+i, n);
        int sumaIz = suma(v, 0, i-1);
        if(v[i] == sumaIz)
            r = s + 1;
        else
            r = s;
    }
    return r;
}

int numVecesPMejorado(int v[], int i, int n, int sumaIz){
    int r;
    if( i == n)
        r = 0;
    else{
        int s = numVecesPMejorado(v, i+1, n,sumaIz + v[i]);
        if(v[i] == sumaIz)
            r = s + 1;
        else
            r = s;
    }
    return r;
}

int numVecesPerfectoPublico(int v[], int n){
    int sumaDr;
    return numVecesPerfecto(v,0,n,0,sumaDr);
}

//P = { 0 <= i < n <= long(v) ^ sumaIz = suma(v,0,i-1)
int numVecesPerfecto(int v[], int i, int n, int sumaIz, int &sumaDr){
    
    if(i == n-1){
        sumaDr = 0;
        r = 0;
    }else
        r = numVecesPerfecto(v, i+1, n, sumaIz + v[i], sumaDr);
        
    if(sumaIz == sumaDr)
            r++;
    
    sumaDr += v[i];
    return r;
}
//Q = { sumaDr = suma(v, i, n-1) ^ r = #k: i <= k <= n: suma(v,0,k-1) = suma(v,k+1,n)


// P = { 0 <= a <= long(v) ^ -1 <= b < long(v) ^ b >= a-1
bool pareado(int v[], int a, int b, int &numPares){
    
    if(b<a){
        r = true;
        numPares=0;
    }
    else{
        bool pareadoIz, pareadoDr;
        int paresIz, paresDr;
        int m = (a+b)/2;
        pareado(v,a,m-1, paresIz, pareadoIz);
        pareadp(v, m+1, b, paresDr, pareadoDr);
        numPares = paresIz + paresDr;
        if(v[m]%2 == 0)
            numPares++;
        r = abs(paresIz . paresDr) <= 1 && pareadoIz && pareadoDr;
    }
    
}
// Q = { r = esPareado(v,a,b)
// esPareado(v,a,b) = [(|pares(v,a,((a+b)/2 - 1)) - pares(v,((a+b)/2 + 1),b|) <= 1 ^
//      esPareado(v,a,((a+b)/2 - 1) ^ esPareado(v, (a+b)/2 + 1, b) ] v b < a] ^
//      numPares = pares(v,a,b)


int fact(int n) {
    int r;
    if(n == 0)
        r = 1;
    else
        r = n * fact(n-1);
    return r;
}

int factMejor(int n, int acu){
    int r ;
    
    if(n==0)
        r=acu;
    else
        r=factMejor(n-1, acu*n);
    return r;
}

//
//
//
//base6Adec(n) = - n si n < 10
//               - base6Adec(n/10)*6 + n%10 si n >= 10





//ANTIGUO MAIN
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    
//    while(resuelve()){
//    	;
//    }
//
//
//    return 0;
//}
//
//bool resuelve(){
//	int n;
//	cin >> n;
//	int v[10000];
//
//	if(n <= 0){
//				return false;
//
//	}
//	
//		int j;
//		for(int i = 0; i < n; i++){
//			cin >> j;
//			v[i] = j;
//		}
////    int s = suma(v,n);
////    cout << cuantas (v,n,suma) << '\n';
//		//cout << pares(v, n) << endl;
//		//cout << sumaBuenos(v, n) << endl;
//		//cout << picos(v, n) << endl;
//		//cout << miradores(v, n) << endl;
//		//cout << gaspariforme(v, n) << endl;
//		//cout << credito(v, n) << endl;
////		//inter(v,n);
////    int k = 0, l = 0;
////    meseta(v,n,k,l);
////    cout << k << " " << l << endl;
//    cout << seisadecimal << endl;
//
//
//		return true;
//			
//}
// cota = n - i;
// I = 0 <= i <= n ^ suma = Ek : 0 <= k < i : v[k]
int suma(int v[], int n){
    int suma = 0;
    for(int i = 0; i < n; i++)
        suma+= v[i];
    return suma;
    
}


// P = { 0 <= n <= long(v) ^ suma = SUMATORIO j : 0 <= j < n : v[j]
int cuantas(int v[], int n, int suma){
    int cuantas = 0;
    int sumaAux = 0;
    
    for (int i = 0; i < n; i++){
        
    }
    return cuantas;
    
}
// Q = {cont = #k: 0 <= k <= n: ocurre(v,n,k)}
// ocurre (v,k,n) = {suma(v,k) == suma(v,n)/2}
// suma(v,n) = {SUMATORIO j : 0 <= j < n: v[j]}


//RECURSIVO NO FINAL
//RECURSION SIMPLE PORQUE SIEMPRE HAY SOLO UNA LLAMADA RECURSIVO EN CADA CAMINO POSIBLE
int mult (int a, int b){
    
    int r;
    
    if(b == 0)
        r = 0;
    else if (b == 1)
        r = a;
    else if ( b % 2 == 0)
        r = mult (2*a, b/2); // ESTO SERIA RECURSIVO FINAL
    else
        r = mult(2*a, b/2) + a; //EL + A HACE Q SEA RECURSIVO NO FINAL
    
    return r;
}

//RECURSION SIMPLE PORQUE SIEMPRE HAY SOLO UNA LLAMADA RECURSIVO EN CADA CAMINO POSIBLE
//RECURSION FINAL
int mcd(int a, int b){
    int r;
    
    if(a == b)
        r = a;
    else if(a > b)
        r = mcd(a - b, b);
    else
        r = mcd(a, b - a);
    return r;
}

//RECURSION MULTIPLE
int fib (int n) {
    int r;
    
    if(n == 0)
        r = 1;
    
    else if (n == 1)
        r = 1;
    else
        r = fib(n-1) + fib(n-2);
    
    return r;
}

void meseta(int v[], int n, int &i, int &j){
    int mes = 0, mesMayor = 0;
    int a = 0, b = 0;
    
    if (n > 0){
        b = 1;
        
        while(b < n){
            
            
            if(v[a] == v[b]){
                if(mes > mesMayor){
                    i = a;
                    j = b;
                }
                b++;
                mes++;
            }
            else{
                a++;
                b++;
                mes = 0;
            }
          
            
            
        }
        
    }
    
    
}


//{ 0 < n <= long(v) ^ ord(v)}
int moda(int v[], int n){
    
    int i, f, m, fm;
    m = v[0]; fm = 1; i = 1; f = 1;
    
    while (i < n) {
        
        if(v[i] == v[i-1])
            f++;
        else f = 1;
        
        if(f > fm){
            m = v[i]; fm = f;
        }
        i++;
    }
    return m;
    
}
// frec(m, v, n) = Max w: 0 <= w < n: frec(v[w], v, n)}
// I = 1 <= i <= n ^ f = frec (v[i-1], v, i) ^ frec(m,v,i) = Max w: 0 <= < i: frec(v[w], v, i) ^
// fm = frec(m,v,i)
// Cota = n - i


void inter(int v[], int n){
int pares = 0;
int impares = 0;
int aux = -1;

for (int i = 1; i < n-1; i++){	
	if(aux != -1){
		if (aux % 2 == 0)
			pares++;
		if (aux % 2 != 0)
			impares++;
	}

	if((v[i-1] % 2 == 0)	&& (v[i+1] % 2 == 0))
		pares++;
	else if((v[i-1] % 2 != 0)	&& (v[i+1] % 2 != 0))
		impares++;


}
cout << pares << " " << impares <<endl;

}

int credito(int v[], int n){
	int cred = 0, credMax = 0;

	for(int i = 0; i < n; i++){
		if (v[i] > 0)
			cred++;
		if(v[i] < 0)
			cred--;

		if(cred > credMax)
			credMax = cred;

	}
	return credMax;
}


//{0 <= n <= long(v)}
bool gaspariforme(int v[], int n){
	int suma = v[0], k = 0;
    bool gasp = true;
    while ((k < n) && gasp){
        suma += v[k];
        gasp = (suma >= 0);
        k++;
    }
   

	return ((k == n) && (suma == 0));
}
// {gasp = #para todo i: 0 <= i < n: sumaParcial (v,i) >= 0 ^ sumaParcial (v, n-1) = 0}
// sumaParcial,(v, p) = Ei: 0 <= i <= p : v[i]

// I = 0 <= k <= n ^ suma = Ei : 0 <= i < k: v[i] ^ gasp = suma >= 0
// Cota = n - k


int miradores(int v[], int n){
	int miradores = 0;
	int mayor = v[n-1];
	for(int i = n-2; i >= 0; i--){
		if(v[i] > mayor){
			miradores++;
			mayor = v[i];
		}

	}

	return miradores;
}

// Q =  miradores = #w: 0 <= w <= n-1: calculaAbadias(v,n)
// calculaAbadias(v,n): para todo j: Ex: 0 <= x <= j <= n : v[x] > v[j]
//  faltaria la w en calculaabadias y asi hacer rango desde w a n


//abadias = #k: 0 <= k < n: mayor(v, k, n)
//mayor(v, k, n) = para todo l: k < l < n : v[k] > v[l]

// abadias = # k :0 <= k < n: v[k] > max(v, k ,n)
// max(v, k, n) = Max w : k < w < n : v[w]


int picos(int v[], int n){
	int picos = 0;
	int mayor = v[0];

	for(int i = 1; i < n; i++){
		if(v[i] > mayor){
			picos += v[i];
			mayor = v[i];
		}

	}

return picos;

}


int sumaBuenos(int v[], int n){
	int a = 2;
	int buenos = 0;
	if (v[0] == 0)
		buenos++;

	for(int i = 1; i < n; i++){
		if(v[i] == a)
			buenos++;
		a = a * 2;
	}

	return buenos;
}

int pares(int v[], int n){

	int pares = 0;

	for(int i = 0; i < n ; i++){
		if (v[i] % 2 == 0)
			pares++;
	}

	return pares;
}


// { 1 <= n <= long(v) ^ p >= 1 ^ord(v)}

int segMax(int v[], int n, int p) //return r
{
    int l = 1;
    int a = 0;
    int b = 1;
    
    while(b < n){
        
        if(v[b] - v[a] < p){
            l = max (l, b - a + 1);
        }else{
            while (v[b] - v[a] >= p) a++;
        }
        b++;
    }
    return l;
    
}

//{ r = Max i, j: 0 <= i <= j < n ^ (v[j] - v[i] < p): j - i + 1}

//invariante en los apuntes


//matrices
const int N = 100, M = 100;

int suma (int v[N][M]){
    
    int s = 0;
    //INVARIANTE = 0 <= i <= N ^s = E f, c: 0 <= f < i ^ 0 <= c < M: v[f][c]
    //COTA = n - i
    for(int i = 0; i <N; i++){
        //INVARIANTE 2 = 0 <= j = M ^
        // s = (E f,c: 0 <= f < i ^ 0 <= c <= M: v[f][c] +
        // (Ec: 0 <= c < j: v[i][c]
        //COTA = n - j
        for(int j = 0; j < M; j++){
            s += v[i][j];
        }
    }
    return s;
}

//division

//{a >= 0 ^ b > 0}
void divEnt(int a, int b, int &c, int &r){
    
    r = a;
    c =0;
    
    //INVARIANTE = 0 <= r <= a ^ a = b*c+r
    //COTA = r
    //ORDEN O(a/b)
    while(r >= b){
        r-=b;
        c++;
    }
}

//{a = b* c + r ^ 0 <= r < b}



//{0 <= n <= long(a)}

bool separacion (bool a[], int n) { //return r
    
    int k = 0;
    while(k < n && a[k])
        k++;
    while(k < n && !a[k])
        k++;
    
    return (k==n);
    
    
}
//r = existe o: 0 <= p <= n: (para todo i: 0 <= i < p: a[i]) ^ (para todo j: p <= j < n: ¬a[j])}







































