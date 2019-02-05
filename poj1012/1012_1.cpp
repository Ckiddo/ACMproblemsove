#include <stdio.h>

int problem;

int ans[] = {2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881,
13482720};

void solve(){
	printf("%d\n", ans[problem-1]);
}

int main(){
	scanf("%d",&problem);
	while(problem != 0){
		solve();
		scanf("%d",&problem);
	}
}