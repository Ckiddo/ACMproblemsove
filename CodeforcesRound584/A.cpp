#include <stdio.h>
#include <algorithm>

int n;
int store[101];
int maxx = -1;

void input(){
	scanf("%d", &n);
	int nu;
	std::fill(store, store + n, 0);
	
	for(int i = 0;i < n;i++){
		scanf("%d", &nu);
		store[nu]++;
		maxx = std::max(maxx, nu);
	}
}

void solve(){
	int count = 0;
	for(int i = 1;i <= maxx;i++){
		bool toadd = false;
		if(store[i] > 0){
			for(int times = 1; i * times <= maxx;times++){
				if(store[i*times] > 0){
					toadd = true;
					store[i*times] = -1;
				}
			}	
		}
		
		if(toadd){
			count++;
		}
	}
	printf("%d\n", count);
}

int main(){
	input();
	solve();
}