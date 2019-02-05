#include <stdio.h>
#include <cstring>

//1 2 3 4 5 6 7 8 9 10 11 12
//A B C D E F G H I J  K  L  

int coins[12]; // 0 not know  
			   // 1 real
			   // +2 h
			   // -2 l
char left[7];
char right[7];
char dir[5];
char word[3][6] = {"light","aaaaa","heavy"};

int abs(int num){
	if(num >= 0){
		return num;
	}
	return -num;
}

void printAns(){
	// for(int i = 0;i < 12;i++){
	// 	printf("%c\t", i + 'A');
	// }
	// printf("\n");
	// for(int i = 0;i < 12;i++){
	// 	printf("%d\t", coins[i]);
	// }
	// printf("\n");
	int mx = coins[0];
	int mxi = 0;
	for(int i = 1;i < 12;i++){
		if(abs(coins[i]) > abs(mx)){
			mx = coins[i];
			mxi = i;
		}
	}
	printf("%c is the counterfeit coin and it is %s.\n", mxi+'A',(mx > 0 ? "heavy":"light"));
}

void solve(){
	memset(coins,0,sizeof coins);
	for(int i = 0;i < 3;i++){
		scanf("%s",left);
		scanf("%s",right);
		scanf("%s",dir);
		if(dir[0] == 'u'){ // up
			for(int l = 0;left[l] != '\0';l++){
				if(coins[left[l] - 'A'] != 1){
					coins[left[l] - 'A'] += 2;
				}
			}
			for(int r = 0;right[r] != '\0';r++){
				if(coins[right[r] - 'A'] != 1){
					coins[right[r] - 'A'] += (-2);
				}
			}
		}else if(dir[0] == 'd'){
			for(int l = 0;left[l] != '\0';l++){
				if(coins[left[l] - 'A'] != 1){
					coins[left[l] - 'A'] += (-2);
				}
			}
			for(int r = 0;right[r] != '\0';r++){
				if(coins[right[r] - 'A'] != 1){
					coins[right[r] - 'A'] += 2;
				}
			}
		}else{
			for(int l = 0;left[l] != '\0';l++){
				coins[left[l] - 'A'] = 1;
			}
			for(int r = 0;right[r] != '\0';r++){
				coins[right[r] - 'A'] = 1;
			}
		}
	}

	printAns();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
}