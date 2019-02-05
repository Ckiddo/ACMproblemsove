#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <functional>

#include <iostream>

int stick_num,st_max,st_sum;
int sticks[64];
int used_sticks[64];int used_sticks_num;

bool hasAns;
int searchLen;
void dfs(int pos,int len){
	if(hasAns){
		return;
	}
	if(used_sticks_num == stick_num){
		hasAns = true;
		return;
	}
	bool once = false;
	if(len == 0){
		len = searchLen;
		pos = 0;
		once = true;
	}
	int lastNum = -1;
	for(int i = pos;i < stick_num;i++){
		if(used_sticks[i] == false && sticks[i] <= len && sticks[i] != lastNum ){

			used_sticks[i] = true;
			used_sticks_num++;
			dfs(i+1,len - sticks[i]);
			used_sticks_num--;
			used_sticks[i] = false;
			lastNum = sticks[i];
			if(once){
				return;
			}
		}
	}
}


void solve(){

	std::sort(sticks,sticks + stick_num,std::greater<int>());
	for(int bl = st_max;bl <= st_sum;bl++){
		if(st_sum % bl == 0 && bl >= st_max){
			// printf("checking %d\n", bl);
			searchLen = bl;
			hasAns = false;
			dfs(0,bl);

			if(hasAns){
				printf("%d\n", bl);
				return;
			}
		}
	}
}
void clear(){
	stick_num = 0;
	st_max = -1;
	st_sum = 0;
}

int main(){
	clear();
	scanf("%d",&stick_num);
	while(stick_num != 0){
		
		for(int i = 0;i < stick_num;i++){
			scanf("%d",&sticks[i]);
			st_sum += sticks[i];
			if(sticks[i] > st_max){
				st_max = sticks[i];
			}
		}
		solve();
		clear();
		scanf("%d",&stick_num);
		
	}
}