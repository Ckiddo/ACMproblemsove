#include <stdio.h>
#include <string.h>
#include <algorithm>

char  str[600003];
char temp[300001];
int str_len;
int hwl[600003];

void init(){
	memset(hwl,0,sizeof(hwl));
	str_len = strlen(str);
}

void show(int * lis, int n){
	for(int i = 0;i < n;i++){
		printf("%d ", lis[i]);
	}
	printf("\n");
}

void solve(){
	init();
	int rightBound = 0;

	for(int i = 1;i < str_len-1;i++){
		int left = i-1;
		int right = i+1;
		int tempCou = hwl[i];
		while(tempCou--){
			if(){
				
			}
			hwl[right] = hwl[left];
		}

		bool needExp = false;
		if(i + hwl[i] >= rightBound){
			needExp = true;
		}
		if(needExp){
			int left = i-1-hwl[i];
			int right = i+1+hwl[i];
			while(0 <= left && right <= str_len-1 && str[left] == str[right]){
				hwl[i]++;
				hwl[right] = hwl[left];
				left--;
				right++;
			}
			rightBound = std::max(rightBound, right-1);
		}
		show(hwl, str_len);
	}
}


int main(){
	scanf("%s",temp);
	memset(hwl,0, sizeof(hwl));
	int len = strlen(temp);
	str[0] = 'A';
	int i = 0,j = 1;
	for(;i < len;i++){
		str[j++] = temp[i];
		str[j++] = 'A';
	}
	str[j] = '\0';


	solve();
}