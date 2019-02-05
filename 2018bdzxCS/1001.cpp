#include <stdio.h>
#include <algorithm>

int N;
int num[1000];
int  S[3];
int max = -1;
void solve(){
	std::sort(num,num+N);
	for(int i = N-1;i>=2;i--){
		for(int j = i-1;j>=1;j--){
			for(int k = j-1;k>=0;k--){
				S[0] = num[i];
				S[1] = num[j];
				S[2] = num[k];
				int tem = 0;
				for(int l = 0;l < 3;l++){
					//printf("%d",S[l]);
					tem += S[l];
				}
				//printf("\n");
				//std::sort(S,S+3);
				if(S[2] + S[1] > S[0] && S[0] > S[1] - S[2] && tem > max){
					max = tem;
				}
			}
		}
	}
}

int main(){

	while(scanf("%d",&N) != -1){
		for(int i = 0;i < N;i++){
			scanf("%d",&num[i]);
		}
		max = -1;
		solve();
		printf("%d\n", max);
	}
}