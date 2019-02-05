#include <stdio.h>

int caN;

int num;

void solve(){
	scanf("%d %d",&caN,&num);
	int ans = (1+num)*(num)/2 + num;
	printf("%d %d\n", caN,ans);
}


int main(){
	int P;
	scanf("%d",&P);
	for(int i = 0;i < P;i++){
		solve();
	}
}