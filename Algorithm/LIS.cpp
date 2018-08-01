#include <stdio.h>
#include <stdint.h>
#include <algorithm>


#ifndef INF
#define INF INT16_MAX
#endif
class LIS{
public:
	int n;
	int* a;
	int* dp;
	LIS(int n){
		this->n = n;
		a = new int[n];
		dp = new int[n];
		std::fill(dp,dp+n,INF);
	}
	void solve(){
		for(int i = 0;i < this->n;i++){
			*std::lower_bound(dp,dp+n,a[i]) = a[i];
		}
		printf("%ld\n", std::lower_bound(dp,dp + n, INF) - dp);;
	}
	
};

int main(){
	LIS l(5);
	l.a[0] = 4;
	l.a[1] = 2;
	l.a[2] = 3;
	l.a[3] = 1;
	l.a[4] = 5;
	l.solve();
}