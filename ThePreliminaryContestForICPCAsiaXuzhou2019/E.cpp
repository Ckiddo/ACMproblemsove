#include <stdio.h>

int n,m;
int   W[500001];
int ans[500001];

void solve(){
	ans[n-1] = -1;
	for(int i = n-2;i >= 0;i--){
		int maxPos = -1;
		for(int j = i+1;j <= n-1;j++){
			if(W[j] >= W[i] + m){
				maxPos = j;
			}
			if(W[j] > W[i] && ans[j] != -1){
				j+=ans[j];
			}
			if(W[j] <= W[i] && ans[j] == -1){
				break;
			}
		}
		if(maxPos == -1){
			ans[i] = -1;
		}else{
			ans[i] = maxPos - i - 1;
		}
	}
	printf("%d", ans[0]);
	for(int i = 1;i < n;i++){
		printf(" %d", ans[i]);
	}
	printf("\n");
}

int main(){
	scanf("%d %d", &n,&m);
	for(int i = 0;i < n;i++){
		scanf("%d", &W[i]);
	}
	solve();
}