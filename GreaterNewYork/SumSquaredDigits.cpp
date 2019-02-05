#include <stdio.h>


int caN;
int b;
int n;
void solve(){
	scanf("%d %d %d",&caN,&b,&n);
	int l = n;
	int ans = 0;
	while(l != 0){
		int te = l % b;
		ans += (te)*(te);
		l = l / b;
	}
	printf("%d %d\n", caN,ans);
}


int main(){
	int P;
	scanf("%d",&P);
	for(int i = 0;i < P;i++){
		solve();
	}
}