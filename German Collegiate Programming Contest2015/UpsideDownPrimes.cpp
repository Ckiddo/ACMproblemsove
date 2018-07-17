#include "stdio.h"
#include "cmath"

char store[20];
char rotate[20];
long long a;
long long b;
bool has347 = false;

void getStore(){
	scanf("%s",store);
}
void getA_Rota(){
	for(int i = 0;i < 20;i++){
		rotate[i] = 'n';
	}
	a = 0;
	for(int i = 0;store[i] != '\0';i++){
		a = a*10;
		a = a + (store[i] - '0');
		if(store[i] == '0' || store[i] == '2' || store[i] == '5' || store[i] == '8' || store[i] == '1'){
			rotate[i] = store[i];
		}else if(store[i] == '6'){
			rotate[i] = '9';
		}else if(store[i] == '9'){
			rotate[i] = '6' ;
		}else if(store[i] == '3' || store[i] == '4' || store[i] == '7'){
			rotate[i] = 'r';
			has347 = true;
		}
	}
}

void getB(){
	b = 0;
	for(int i = 19;i >=0;i--){
		if(rotate[i] <= '9' && rotate[i] >= '0'){
			b = b*10;
			b += (rotate[i] - '0');
		}
	}
}

void getin(){
	getStore();
	getA_Rota();
	if(has347){
		return;
	}else{
		getB();
	}
	
	
}

bool isPrime(long long a){
	if(a == 2){
		return true;
	}
	if(a == 1 || a == 0){
		return false;
	}
	long long tmp = std::sqrt(a);
	for(long long i = 2;i <= tmp + 1;i++){
		if(a % i == 0){
			//printf("%lld Not Prime\n", a);
			return false;
		}
	}
	//printf("%lld is Prime\n", a);
	return true;
}

void judge(){
	if(isPrime(a) && isPrime(b)){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}
void clear(){
	for(int i = 0;i < 20;i++){
		store[i] = 'e';
		rotate[i] = 'n';
	}
	a = 0;
	b = 0;
	has347 = false;
}

void solve(){
	clear();
	getin(); // 
	if(has347){
		printf("no\n");
	}else{
		judge();
	}
}
int main(){
	solve();
}