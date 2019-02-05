#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cmath>
long F[20000001];
long ff[20000001];
bool freeNum[20000001];
int getYinzi(int N,int start){
	for(int i = start;i <= N;i++){
		if(N % i == 0){
			return i;
		}
	}
	return 1;
}

std::vector<int> getZhiYinshu(int N){
	int NN = N;
	std::vector<int> ans;
	int yinzi = 0;
	int start  =2;
	//printf("getZhiYinshu %d\n", N);
	for(;(yinzi = getYinzi(NN,start)) != 1;){
		ans.push_back(yinzi);
		//printf("yinzi:%d\n",yinzi );
		while(NN % yinzi == 0){
			NN = NN / yinzi;
		}
		start = yinzi + 1;
	}
	//printf("ok\n");
	return ans;
}



std::vector<int> getPossible(std::vector<int> v,int N){
	int vSzie = std::pow(2,v.size());
	std::vector<int> ans;
	ans.push_back(1);
	bool notNeed = false;
	for(int i = 1;i < vSzie;i++){
		int t = i;
		int anss = 1;
		for(int j = 0;j < v.size();j++){
			if((t & 1) == 1){
				anss *= v[j];
			}
			t = t>>1;
		}
		ans.push_back(anss);
		if(anss == N){
			notNeed = true;
		}
	}
	if(!notNeed){
		ans.push_back(N);
	}
	return ans;
}

long f(int N){
	if(ff[N] != -1){
		return ff[N];
	}else{
		long ans = 0;
		//printf("%d %d\n", N,0);
		//
		std::vector<int> zhiyinshu = getZhiYinshu(N);
		// printf("%d :\n", N);
		// for(auto i : zhiyinshu){
		// 	std::cout << i << " ";
		// }
		// std::cout<<std::endl;
		std::vector<int> possible = getPossible(zhiyinshu,N);
		// printf("%d :\n", N);
		// for(auto i : possible){
		// 	std::cout << i << " ";
		// }
		// std::cout<<std::endl;
		for(auto i:possible){
			if(freeNum[i] && freeNum[N/i]){
				//printf("%d %dfree\n", i,N/i);
				ans++;
			}
		}
		//printf("%d : %d\n", N,ans);
		return ff[N] = ans;
	}
}

long getSum(int N){
	if(F[N] != -1){
		return F[N];
	}else if(N == 1){
		return ff[N] = F[N] = 1;
		//return F[N] = getSum(N-1) + f(N);
	}else{
		return F[N] = f(N) + getSum(N-1);
	}
}

void solve(){

	int n;
	scanf("%d",&n);
	printf("%ld\n", getSum(n));
}



int main(){
	int T;
	scanf("%d",&T);
	std::fill(F,F + 20000001,-1);
	std::fill(ff,ff+20000001,-1);
	std::fill(freeNum,freeNum + 20000001,true);
	for(int i = 2;i*i <= 20000000;i++){
		int pf = i*i;
		for(int j = 1;j*pf <= 20000000;j++){
			freeNum[j*pf] = false;
		}
	}
	for(int i = 0;i < T;i++){
		solve();
	}
}