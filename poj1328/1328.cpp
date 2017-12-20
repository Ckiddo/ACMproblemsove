#include <stdio.h>

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	int store[1000][2];
	int casenum = 1;
	while (n != 0 && d != 0) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", store[i][0], store[i][1]);
		}
		int ans = 0;
		int tar = 0;
		int x = findx(store[0][0],store[0][1],d);
		if(x != ){

		}
		for(int i = 0;i < n;){

		}	


		printf("Case %d: %d", casenum, ans);
		scanf("%d %d", &n, &d);
	}
}

















































