#include <stdio.h>
#include <utility>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int > a,pair<int,int> b){
	if(a.first > b.first){
		return false;
	}else if(a.first == b.first){
		if(a.second <= b.second){
			return false;
		}else{
			return true;
		}
	}else{
		return true;
	}
}
int main(){
	int N,T;
	scanf("%d %d",&N,&T);
	pair<int,int> store[N];
	for(int i = 0;i < N;i++){
		int st,en;
		scanf("%d %d",&st,&en );
		store[i].first = st;
		store[i].second = en;
	}
	sort(store,store + N,cmp);
	// for(int i = 0;i < N;i++){
	// 	printf("%d %d\n",store[i].first,store[i].second );
	// }
	// printf("store after first sort:\n");
	// for(int k = 0;k < N;k++){
	// 	printf("%d %d\n",store[k].first,store[k].second );
	// }
	int start = 1;
	int answer = 0;
	for(int i = 0;i < N && (start <= T);i++){
		if(start > store[i].second){
			continue;
		}
		if(start >= store[i].first){
			start = store[i].second + 1;
			answer++;
			//printf("answer:%d %d\n",store[i].first,store[i].second );
			int j = i+1;
			for(j = i+1;j < N;j++){
				if(store[j].first < start){
					store[j].first = start;
				}else{
					break;
				}
			}
			// printf("store:\n");
			// for(int k = 0;k < N;k++){
			// 	printf("%d %d\n",store[k].first,store[k].second );
			// }
			// printf("px%d %d\n",i + 1,j + 1 );
			sort(store + i + 1,store + j + 1,cmp);
			// printf("store:\n");
			// for(int k = 0;k < N;k++){
			// 	printf("%d %d\n",store[k].first,store[k].second );
			// }

		}
	}
	if(start > T){
		printf("%d\n", answer);
	}else{
		printf("-1\n");
	}
}