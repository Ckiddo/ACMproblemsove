#include <stdio.h>

int N,M,K;
int KK[10][2];




bool getin(){

	if(scanf("%d %d",&N,&M) != -1){
		scanf("%d",&K);
		int x,y;
		for(int i = 0;i < K;i++){			
			scanf("%d %d",&x,&y);
			KK[i][0] = x;
			KK[i][1] = y;
		}
		return true;
	}
	return false;
}
int abs(int a){
	if(a < 0){
		return -a;
	}
	return a;
}
int dis(int x1,int y1,int x2,int y2){
	return (abs(x1 - x2))+(abs(y1 - y2));
}

void solve(){
	int minx = 2001;
	int miny = 2001;
	int maxst = -1;
	for(int i =1 ;i <= N;i++){
		for(int j = 1;j <= M;j++){
			int mindis = 4002;
			for(int k = 0;k < K;k++){
				int te = dis(i,j,KK[k][0],KK[k][1]);
				if(te < mindis){
					mindis = te;
				}
			}
			if(mindis > maxst){
				maxst = mindis;
				minx = i;
				miny = j;
			}
		}
	}
	printf("%d %d\n", minx,miny);
}
int main(){

	while(getin()){
		solve();
	}
}