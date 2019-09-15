#include <stdio.h>
#include <algorithm>

#ifndef MAX
#define MAX 100
#endif

int n,W;
int w[MAX], v[MAX];
int maxVal = -1;
void search(int pos, int remainW,int value){
	if(pos == n-1){
		maxVal = std::max(maxVal, value);
		return;
	}
	if(remainW - w[pos+1] >= 0){
		search(pos+1,remainW - w[pos+1],value+v[pos+1]);
	}	
	search(pos+1,remainW,value);
}

void solve(){
	search(-1,W,0);
	printf("%d\n", maxVal);
}
void init(){
	n = 4;
	W = 5;
	int tw[4] = {2,1,3,2};
	int tv[4] = {3,2,4,2};
	for(int i = 0;i < 4;i++){
		w[i] = tw[i];
		v[i] = tv[i];
	}
}

int main(){
	init();
	solve();
}