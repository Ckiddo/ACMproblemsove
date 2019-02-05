#include <stdio.h>
#include <algorithm>

int n;
int A[1001][1001];
int q;
int l,r;

int search(int le,int ri){
	if(A[le][ri] != -1){
		return A[le][ri];
	}else{
		int mid = (le + ri) / 2;
		return A[le][ri] = std::max(search(le,mid), search(mid + 1,ri));
	}
}

void output(){
	int ans = search(l,r);
	printf("%d\n",ans);
}

void solve(){
	scanf("%d",&n);
	for(int i = 0;i < 1001;i++){	
		for(int j = 0;j < 1001;j++){
			A[i][j] = -1;
		}
	}
	for(int i = 1;i <= n;i++){
		scanf("%d",&A[i][i]);
	}
	scanf("%d",&q);
	for(int i = 0;i < q;i++){
		scanf("%d %d",&l,&r);
		output();
	}

}

int main(){
	int t;
	scanf("%d",&t);
	for(int i = 0;i < t;i++){
		solve();
	}
}