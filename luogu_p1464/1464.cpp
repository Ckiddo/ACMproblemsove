#include <stdio.h>
typedef long long ll;
ll a,b,c;
ll ans;
ll record[21][21][21];
int mark[21][21][21];

ll ww(ll t1,ll t2,ll t3){
	if(t1 <= 0 || t2 <= 0 || t3 <= 0){
		return 1;
	}
	if(t1 > 20 || t2 > 20 || t3 > 20){
		return ww(20,20,20);
	}
	if(t1 < t2 && t2 < t3){
		if(mark[t1][t2][t3]){
			return record[t1][t2][t3];
		}else{
			mark[t1][t2][t3] = 1;
			return record[t1][t2][t3] = ww(t1,t2,t3-1) + ww(t1,t2-1,t3-1) - ww(t1,t2-1,t3);
		}
		
	}
	if(mark[t1][t2][t3]){
		return record[t1][t2][t3];
	}else{
		mark[t1][t2][t3] = 1;
		return record[t1][t2][t3] = ww(t1-1,t2,t3) + ww(t1-1,t2-1,t3) + ww(t1-1,t2,t3-1) - ww(t1-1,t2-1,t3-1);
	}
	
}

ll solve(){

	if(a <= 0 || b <= 0 || c <= 0){
		return 1;
	}
	if(a > 20 || b > 20 || c > 20){
		return ww(20,20,20);
	}
	if(a < b && b < c){
		return ww(a,b,c-1) + ww(a,b-1,c-1) - ww(a,b-1,c);
	}
	return ww(a-1,b,c) + ww(a-1,b-1,c) + ww(a-1,b,c-1) - ww(a-1,b-1,c-1);
}

void getin(){
	for(int i = 0;i < 21;i++){
		for(int j = 0;j < 21;j++){
			for(int k = 0;k < 21;k++){
				mark[i][j][k] = 0;
			}
		}
	}
	while(scanf("%lld %lld %lld",&a,&b,&c) != -1){
		if(a == -1 && b == -1 && c == -1){
			break;
		}

		ans = solve();

		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c, ans);
	}
}

int main(){
	getin();
}