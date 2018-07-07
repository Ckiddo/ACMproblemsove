#include <stdio.h>

int hangdao(int deg){
	int tem;
	if(deg>184 && deg <= 360){
		tem = deg-180;
	}else if(deg>=0 && deg <=4){
		tem = deg+180;
	}else{
		tem = deg;
	}
	int ans = (tem+5)/10;
	return ans;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int num;
		scanf("%d",&num);
		int ans = hangdao(num);
		printf("%0.2d\n", ans);
	}
}