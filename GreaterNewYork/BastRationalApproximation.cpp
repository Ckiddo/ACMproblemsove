#include <stdio.h>
#include <cmath>
#include <string>
#include <cstdlib>


int _caN;
int _M;
char _ssx[30];
std::string _sx;
long double _x;

bool huzhi(long a,long b){
	if(a == 1){
		return true;
	}
	if(b % a == 0){
		return false;
	}
	return true;
}
void solve(){
	scanf("%d %d %s",&_caN,&_M,_ssx);
	_sx = std::string(_ssx);
	_x = std::strtold(_sx,0);
	printf("get:%d %d %s,%Lf\n", _caN,_M,_ssx,_x);
	long double delta = 1;
	long _q = -1;
	long _p = -1;
	for(long q = 2;q < _M;q++){
		printf("q:%ld\n",q);
		for(long p = 1;p < q;p++){
			if(!huzhi(p,q)) break;
			long double tem= std::abs((long double)p/q - _x);
			//printf("%d /%dnew delta : %Lf\n",p,q, tem);
			if(tem < delta){
				delta = tem;
				_p = p;
				_q = q;
			}
		}
	}
	printf("%d %ld/%ld\n", _caN,_p,_q);
}

long double g1(long double x, long long p,long long a,long long b){
	return (a*b - x*p*b*b - x*b*b)/(a*a - 2*a*b*x);
}
long double g2(long double x,long long p,long long a,long long b){
	return (b*b*x - x*p*b*b - a*b)/(a*a - 2*a*b*x);
}


int main(){
	int P;
	scanf("%d",&P);
	for(int i = 0;i < P;i++){
		solve();
	}
	// long double x = 0.141592653589793238;
	// for(int i = 1;i < 14094;i++){
	// 	printf("%d: %Lf %Lf\n",i ,g1(x,i,141592,1000000),g2(x,i,141592,1000000));
	// }
	// printf("%Lf %Lf\n",g1(x,36,36,254),g2(x,36,36,254));
}