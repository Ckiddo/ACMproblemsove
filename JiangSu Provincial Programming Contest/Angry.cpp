#include <stdio.h>
#include <vector>

int N;
long K;
std::vector<long> A;
std::vector<long> C;
long long _ans;
long mod = 1000000007;

bool getin(){
	A.clear();
	C.clear();
	int t;
	if( t = scanf("%d %ld",&N,&K) != -1 && t != EOF){
		A.push_back(0);
		int i;
		for(i = 0;i < N;i++){
			long tem;
			scanf("%ld",&tem);
			A.push_back(tem);
		}
		for(;i < K;i++){
			A.push_back(-1);
		}
		C.push_back(0);
		for(i = 0;i < N;i++){
			long tem;
			scanf("%ld",&tem);
			C.push_back(tem);
		}
	}else{
		return false;
	}
	return true;
}

long long Ac(long p){
	if(A[p] != -1){
		return A[p];
	}
	long long tem = 0;
	for(int i = 1;i <= N;i++){
		tem = (tem + C[i] * Ac(p-i))%mod;
	}
	return A[p] = tem;
}

void solve(){
	_ans = Ac(K);
	printf("%lld\n", _ans % mod);
}

int main(){
    while(getin()){
        solve();
    }
}
