
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
int suma(inv v[], int n);
int cuantas(int v[], int n, int suma);

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
	int v[10000];

	if(n <= 0){
				return false;

	}
	
		int j;
		for(int i = 0; i < n; i++){
			cin >> j;
			v[i] = j;
		}
    int s = suma(v,n);
    cout << cuantas (v,n,suma) << '\n';
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


		return true;
			
}
// cota = n - i;
// I = 0 <= i <= n ^ suma = Ek : 0 <= k < i : v[k]
int suma(inv v[], int n){
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
        suma += v[k]
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
            l = max (l, b - a + 1)
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
    while(k < n && v[k])
        k++;
    while(k < n && !v[k])
        k++;
    
    return (k==n);
    
    
}
//r = existe o: 0 <= p <= n: (para todo i: 0 <= i < p: a[i]) ^ (para todo j: p <= j < n: ¬a[j])}







































