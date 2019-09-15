#include <stdio.h>

int w;
int main(){
	scanf("%d", &w);
	if(w & 1){
		printf("NO\n");
	}else{
		if(w == 2){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
		
	}
}