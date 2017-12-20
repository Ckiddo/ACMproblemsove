#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int map;
int answer;

vector<pair<int ,int> > store;
vector<pair<int ,int> > store2;

int temp[4] = {8,4,2,1};

void change(int x,int y){
	int mc = 0;
	for(int i = 0;i < 4;i++){
		if(x == i){
			mc = (mc<<4) + 15;
		}else{
			mc = (mc<<4) + temp[y];
		}
	}
	map = map ^ mc;
}

bool solved(){
	return (map == 0);
}

void solve(int x,int s){
	if(x == 16){return;}
	if(solved()){
		if(s < answer){
			answer = s;
			store2.clear();
			int n = store.size();
			for(int i = 0;i < n;i++){
				store2.push_back(store[i]);
			}
		}

		return;
		//printf("size:%d\n", (int)store.size());
	}else{

		solve(x+1,s);

		change(x%4,x/4);
		pair<int ,int> temp;
		temp.first = x%4;
		temp.second = x/4;
		store.push_back(temp);

		solve(x+1,s+1);

		if(solved()){
			if(s+1 < answer){
				answer = s+1;
				store2.clear();
				int n = store.size();
				for(int i = 0;i < n;i++){
					store2.push_back(store[i]);
				}
			}
		}
		change(x%4,x/4);
		//printf("%d %d\n", store.top().first,store.top().second);
		store.pop_back();

		// not change

		// change
	}
}

bool cmp(pair<int ,int > &a,pair<int,int> &b){
	if(a.first < b.first){
		return true;
	}else{
		if(a.second < b.second){
			return true;
		}
	}
	return false;
}

int main(){
	map = 0;
	char c;
	answer = 20;
	for(int i = 0; i < 4;i++){
		for(int j = 0;j < 4;j++	){
			c = getchar();
			map = (map<<1) ^ (c == '+' ? 1:0);
		}
		getchar();
	}
	solve(0,0);
	printf("%d\n", answer);
	int n = store2.size();
	sort(store2.begin(),store2.end());
	for(int i = 0;i < n;i++){
		printf("%d %d\n", store2[i].first+1,store2[i].second+1);
	}
	return 0;
}