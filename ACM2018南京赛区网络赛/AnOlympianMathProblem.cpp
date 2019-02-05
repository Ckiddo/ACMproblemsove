#include <stdio.h>
#ifndef ll
#define ll long long
#endif
void solve(){
	ll n;
	scanf("%lld",&n);
	printf("%Ld\n", n);
}


int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		solve();
	}
}