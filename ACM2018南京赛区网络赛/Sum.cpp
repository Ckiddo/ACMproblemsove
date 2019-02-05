#include<stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>

bool bugFreeNum[20000001];
long F[20000001];

int getYinZi(int n,int start){
	for(int i = start;i <= n;i++){
		if(n % i == 0){
			return i;
		}
	}
	return 1;
}
long f(int i){
	if(F[i] != -1){
		return F[i];
	}
	std::vector<int> zhiyinshu;
	int ans = 0;
	int ff = i;
	int yinzi = 0;
	int start = 2;
	for(;(yinzi = getYinZi(ff,start)) != 1;){
		zhiyinshu.push_back(yinzi);
		while(ff%yinzi == 0){
			ff = ff/yinzi;
		}
		start = yinzi+1;
	}
	printf("%d的因子们：\n", i);
	for(int j = 0;j < zhiyinshu.size();j++){
		printf("%d\n", zhiyinshu[j]);
	}
	printf("end\n");


	return F[i] = ans;
}

void solve(){

	int n;
	scanf("%d",&n);
	long ans = 0;

	for(int i = 1;i <= n;i++){
		ans += f(i);
	}
	printf("%ld\n", ans);
}

int main(){
	int T;
	scanf("%d",&T);
	std::fill(F,F+20000001,-1);
	std::fill(bugFreeNum,bugFreeNum + 20000001,true);
	for(int i = 2;i*i <= 20000000;i++){
		int pf = i*i;
		for(int j = 1;j*pf <= 20000000;j++){
			bugFreeNum[j*pf] = false;
		}
	}
	for(int i = 0;i < T;i++){
		solve();
	}

}