#include <stdio.h>
#include <cmath>

int getnewN(int n){
	if (n == 1)
		return 1;
	int count = log(n-1)/log(2);
	return pow(2,count+1);
}
int** Strassen(int** a,int** b,int n){
	int N = getnewN(n);
	int C[N][N];

}

int main(){
	for(int i = 1;i <= 100;i++){
		printf("%d %d\n", i,getnewN(i));
	}
}