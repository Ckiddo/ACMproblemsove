# include <stdio.h>
# include <algorithm>
int store[1024];
int store2[1024];
int N;


bool solve(){
	std::sort(store,store+N);

	for(int i = 0;i < N;i++){
		if(store[i] != store2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d",&N);

	for(int i = 0;i < N;i++){
		int a;
		scanf("%d",&a);
		store[i] = a;
		store2[i] = a;
		//printf("%d\n", store[i]);
	}
	if(solve()){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}