#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int R,n;
	scanf("%d %d",&R,&n);
	while(R!= -1 && n != -1){
		int store[n];
		for(int i = 0;i < n;i++){
			scanf("%d",&store[i]);
		}
		sort(store,store+n);
		int nm = store[0]; // need mark
		int center;
		int answer = 0;
		for(int i = 0;i <= n;i++){
			// find center
			if(i == n ||store[i] > nm + R){
				i--;
				center = store[i];
				answer++;
				for(;i < n;i++){
					if(store[i] > center + R){
						nm = store[i];
						break;
					}
				}
			}
		}
		printf("%d\n", answer);
		scanf("%d %d",&R,&n);
	}
}