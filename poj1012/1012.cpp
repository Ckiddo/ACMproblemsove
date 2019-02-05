#include <stdio.h>

int problem;

bool check(int step){
	int remainder = problem * 2;
	int steps = step;
	int killNum;
	while(true){
		killNum = steps % remainder;
		if(killNum == 0){killNum = remainder;}

		if(remainder > problem && killNum <= problem){
			return false;
		}

		steps = step - (remainder - killNum);
		remainder--;

		if(remainder == problem){
			return true;
		}

		
	}
}

void solve(){
	int ans = problem + 1;
	while(true){
		if(check(ans)){
			printf("%d\n", ans);
			return;
		}
		ans++;
	}
}

int main(){
	scanf("%d",&problem);
	while(problem != 0){
		solve();
		scanf("%d",&problem);
	}
}