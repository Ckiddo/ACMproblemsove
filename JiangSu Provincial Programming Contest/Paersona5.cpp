#include <stdio.h>

int N;
long long mod = 1000000007;

int getnewkind(int boxnum,int addnum){
	int needdiv = 1;
	long long needmul = 1;
	for(int i = boxnum +1;i < boxnum + addnum ;i++){
		needmul = (needmul * i) % mod;
	}
	for(int i = 2;i < boxnum + 1 && i <= addnum;i++){
		needdiv = needdiv * i;
	}

}

bool getin(){
	if(scanf("%d",&N) != -1){
		int boxnum;
		scanf("%d",&boxnum);
		for(int i = 1;i < N;i++){
			int addnum;
			scanf("%d",&addnum);
			int newkind = getnewkind(boxnum,addnum);
		}
	}
}
int main(){

	while(getin()){
		solve()
	}
}