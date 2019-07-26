#include<stdio.h>
#include<algorithm>
#include <queue>
#include <functional>
#include <vector>

typedef long long ll;

#ifndef MAX_N
#define MAX_N 20002
#endif

ll N;
std::priority_queue<ll, std::vector<ll>,std::greater<ll> > store;
ll len;


void getin(){
	scanf("%lld",&N);
	ll t;
	for(int i = 0;i < N;i++){
		scanf("%lld",&t);
		store.push(t);
	}
}

void solve(){
	ll t1,t2;
	ll ans = 0;
	while(store.size() > 1){
		t1 = store.top();store.pop();
		t2 = store.top();store.pop();
		store.push(t1 + t2);
		ans += (t1 + t2);
	}
	printf("%lld\n", ans);
}

int main(){
	getin();
	solve();
}