#include <stdio.h>

char _yuanwen[51];
char _miwen[51];
char miwen[51];
int n,m;

void getin(){

	scanf("%d %d",&n,&m);
	getchar();
	scanf("%s",_yuanwen);
	scanf("%s",_miwen);
	scanf("%s",miwen);
}

void solve(int t){
	getin();
	int tem = _miwen[0] - _yuanwen[0];
	if(tem < 0){
		tem += 26;
	}
	// output:
	printf("Case #%d: ", t+1);
	for(int i = 0;i < m;i++){
		miwen[i] = miwen[i] - tem;
		if(miwen[i] < 'A'){
			miwen[i] += 26;
		}
		printf("%c", miwen[i]);
	}
	printf("\n");
}


int main(){
	int T;
	scanf("%d",&T);
	for(int t = 0;t < T;t++){
		solve(t);
	}

}