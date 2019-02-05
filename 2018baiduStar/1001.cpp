#include <stdio.h>
#include <set>
#include <cmath>
#include <algorithm>

int _caseNum;

void solve(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	int store[n];
	char line[11];
	for(int i = 0;i < n;i++){
		scanf("%s",line);
		int tem = 0;
		for(int j = 0;line[j] != '\0';j++){
			if(line[j] == 'A'){
				tem = tem << 1;
				tem += 1;
			}else{
				tem = tem << 1;
			}
		}
		store[i] = tem;
	}
	int count = 0;
	int ans = 0;
	int shangxian = pow(2,m);
	int tongji[1001];int sz = 0;
	for(int i = 1;i < shangxian;i++){
		//printf("与%d且：\n",i);
		for(int j = 0;j < n;j++){

			tongji[sz++] = (i & store[j]);
			//printf("%d\n", tongji[j]);
		}
		std::sort(tongji,tongji+sz);
		while(sz != 0){
			int t = tongji[sz-1];
			int tg = std::upper_bound(tongji,tongji+sz,t) - std::lower_bound(tongji,tongji+sz,t);
			sz = sz - tg;
			count += tg*sz;
		}
		//printf("有%d对不同\n", count);
		if(count >= k){
			ans++;
		}
		count = 0;
	}
	printf("Case #%d: %d\n", _caseNum,ans);
	
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i =0;i < T;i++){
		_caseNum = i+1;
		solve();
	}
}