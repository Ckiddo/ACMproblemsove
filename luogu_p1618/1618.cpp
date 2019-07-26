#include <stdio.h>
#include <algorithm>

int A,B,C;

int main(){
	scanf("%d %d %d",&A,&B,&C);
	int a,b,c;
	bool printed = false;
	for(int a = 100;a < 1000;a++){
		if(a * B % A != 0 || (a * C) % A != 0){
			continue;
		}
		b = (a * B) / A;
		c = (a * C) / A;
		if(!(100 < b && b < 1000 && 100 < c && c < 1000)){
			continue;
		}
		int store[10];
		int len = 0;
		int ansa = a;
		int ansb = b;
		int ansc = c;
		// printf("check %d %d %d\n", a,b,c);
		for(int i = 0;i < 3;i++){
			store[len++] = ansa % 10;
			store[len++] = ansb % 10;
			store[len++] = ansc % 10;
			ansa = ansa/10;
			ansb = ansb/10;
			ansc = ansc/10;
		}
		bool con = false;
		std::sort(store,store + 9);
		for(int i = 0;i < 9;i++){
			if(store[i] != (i+1)){
				con = true;
			}
		}
		if(con) continue;
		printf("%d %d %d\n", a,b,c);
		printed = true;
	}
	if(!printed){
		printf("No!!!\n");
	}
}