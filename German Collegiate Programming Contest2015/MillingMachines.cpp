#include<stdio.h>

int W,S;
int X,Y;
int store[10000][101];// 10000块板子，每块板子100种高 store[i][X] = maxY;
int mill[100]; // mill每个方法分别的100种长度
int milltem[100];
void getin(){
	W = 0;
	S = 0;
	X = 0;
	Y = 0;
	for(int i = 0;i < 10000;i++){
		for(int j = 0;j < 100;j++){
			store[i][j] = 0;
		}
	}
	for(int i = 0;i < 100;i++){
		mill[i] = 0;
	}
	scanf("%d %d",&W,&S);
	scanf("%d %d",&X,&Y);
	for(int i = 0;i < W;i++	){
		int maxY = 0;
		for(int j = 0;j < X;j++){
			int tem;
			scanf("%d",&tem);
			if(tem > maxY){
				maxY = tem;
			}
			store[i][j] = tem;
		}
		store[i][X] = maxY;
	}
	for(int i = 0; i < S;i++){
		for(int j = 0;j < X;j++){
			int tem;
			scanf("%d",&tem);
			if(tem > mill[j]){
				mill[j] = tem;
			}
		}
	}
}

int min(int a,int b){
	if (a < b){
		return a;
	}else{
		return b;
	}
}

void millingOutput(){
	for(int i = 0;i < W;i++){
		for(int j = 0;j < X;j++	){
			milltem[j] = Y - mill[j];
			store[i][j] = min(store[i][j],milltem[j]);
			printf("%d", store[i][j]);
			if(j != X-1){
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
}


void solve(){
	getin();
	millingOutput();

}

int main(){
	solve();
}