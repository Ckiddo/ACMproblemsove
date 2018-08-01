#include <stdio.h>
#include <algorithm>

/*
生成n的全排列

*/

#ifndef MAX_N
#define MAX_N 4
#endif
bool used[MAX_N];
int perm[MAX_N];
int perm2[MAX_N];

void permutation1(int pos,int n){
	if(pos == n){
		for(int i = 0;i < MAX_N;i++){
			printf("%d ", perm[i]);
		}
		printf("\n");
	}
	for(int i = 0;i < MAX_N;i++){
		if(!used[i]){
			perm[pos] = i;
			used[i] = true;
			permutation1(pos+1,n);
			used[i] = false;
		}
	}
}

void permutation2(int n){
	for(int i = 0;i < n;i++){
		perm2[i] = i;
	}
	do {
		for(int i = 0;i < n;i++){
			printf("%d ", perm2[i]);
		}
		printf("\n");
	}while(std::next_permutation(perm2,perm2 + n));
}


int main(){
	// permutation1(0,MAX_N);
	 permutation2(MAX_N);
}