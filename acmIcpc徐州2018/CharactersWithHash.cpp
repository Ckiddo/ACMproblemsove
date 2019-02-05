#include <stdio.h>

int _length;
char _letter;
char str[1000000];

void compute(){
	int count = 0;
	bool canCount = false;
	for(int i = 0;str[i] != '\0';i++){
		if(str[i] != _letter){
			canCount = true;
		}
		if(canCount){
			count++;
		}
	}
	printf("%d\n", count*2);
	// for(int i = 0;str[i] != '\0';i++){
	// 	printf("%d ", str[i] - _letter);
	// }
	// printf("\n");
}
void solve(){
	scanf("%d %c\n",&_length,&_letter);
	scanf("%s",str);
	compute();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}