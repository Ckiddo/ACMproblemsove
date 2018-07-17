#include<stdio.h>

int n,m;
double pn,pm;

void getin(){
	scanf("%d %d",&n,&m)
}
void computePn(){
	
}
void computePm(){

}


void solve(int i){
	getin();
	computePn();
	computePm();
	output(i);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		solve(i);
	}

}