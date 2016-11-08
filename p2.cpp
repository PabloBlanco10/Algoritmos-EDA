
#include <iostream>
using namespace std;

bool resuelve();
void inter(int v[], int n);


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
		
	
		inter(v,n);


		return true;
			
}
// P = { 0 <= N <= long(v)}
void inter(int v[], int n){

	int pares = 0, impares = 0;

	for (int i = 1; i < n-1; i++){	

		if((v[i-1] % 2 == 0)	&& (v[i+1] % 2 == 0))
			pares++;

		else if((v[i-1] % 2 != 0)	&& (v[i+1] % 2 != 0))
			impares++;

	}
	cout << pares << " " << impares <<endl;
}
	// Q = { p = #i: 0 <= i < n : pares(v[i])
//		^ q = #j : 0 <= j < n :impares(v[i]) }
// pares(v[i]) =  v[i+1] ^ v[i-1] % 2 = 0; 
// impares(v[i]) = v[i+1] ^ v[i-1] % 2 != 0; 
