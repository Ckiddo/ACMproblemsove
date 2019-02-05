#include <stdio.h>
#include <list>
#include <vector>
#include <iostream>

int N,Q;
int bh;
int u,w,val;

int   v;
std::vector<std::list<int> > vec;


void read(int &x){
	char ch = getchar();x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar());
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}
void _1queAdd(int u,int po,int val){
	if(po == 1){
		vec[u].push_back(val);
	}else{
		vec[u].push_front(val);
	}
}

void _2queDel(int u,int po){
	if(po == 1){
		if(vec[u].size() > 0){
			int t = vec[u].back();
			vec[u].pop_back();
			printf("%d\n", t);
			//std::cout << vec[u]<<"\n";
			// for (int n : vec[u]) {
			// 	printf("%d ", n);
			// }
			// printf("\n");
		}else{
			printf("-1\n");
		}
	}else{
		if(vec[u].size() > 0){
			int t = vec[u].front();
			vec[u].pop_front();
			printf("%d\n", t);
			//std::cout<<vec[u]<<"\n";
			// for (int n : vec[u]) {
			// 	printf("%d ", n);
			// }
			// printf("\n");
		}else{
			printf("-1\n");
		}
	}
}

void _3queAdd(int u,int sx,int v){
	if(sx == 1){
		vec[v].reverse();
		vec[u].splice(vec[u].end(),vec[v]);
	}else{
		vec[u].splice(vec[u].end(),vec[v]);
	}
	// printf("3_:");
	// for (int n : vec[u]) {
	// 	printf("%d ", n);
	// }
	// printf("\n");
}

void output(int u){
	
}


void getin(){
	for(int i = 0;i < Q;i++){
		read(bh);
		if(bh == 1){
			read(u);read(w);read(val);
			_1queAdd(u,w,val);
		}else if(bh == 2){
			read(u);read(w);
			_2queDel(u,w);
		}else{
			read(u);read(v);read(w);
			_3queAdd(u,w,v);
		}
	}
}

void shiyan(){
	int t,b;
	read(t);
	read(b);
	printf("t%d %d\n",t ,b);
}

int main(){
	while(scanf("%d %d",&N,&Q) != -1){
		for(int i = 0;i < vec.size();i++){
			vec[i].clear();
		}
		vec.clear();
		for(int i = 0;i <= N;i++){
			vec.push_back(*new std::list<int>());
		}
		getin();
		//solve();
	}
}