#include <stdio.h>
#include <vector>

int MX,MY,N;
int store[100000][2];
int ans = -1;
int tem = 0;
struct Edge{
	int x1,y1,x2,y2;
	Edge(int a,int b,int c,int d){
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};
std::vector<Edge> vec;
void getin(){
	scanf("%d %d %d",&MX,&MY,&N);
	for(int i = 0;i <N;i++){
		scanf("%d %d",&store[i][0],&store[i][1]);
	}
}

void addEdge(int x1,int y1,int x2,int y2){
	vec.push_back(*new Edge(x1,y2,x2,y2));
}
void delEdge(int x1,int y1,int x2,int y2){
	vec.pop_back();
}
bool cross(int x1,int y1,int x2,int y2,&Edge e){
	int ACx = x2 - x1;
	int ACy = y2 - y1;
	int 
}
bool allow(int x1,int y1,int x2,int y2){
	for(int i = 0;i < vec.size();i++){
		if(cross(x1,y1,x2,y2,vec[i])){
			return false;
		}
	}
	return true;
}


void digui(int po){
	if(po == N){
		if(tem < ans || ans == -1){
			ans = tem;
		}
	}else{
		// 上
		if(allow(store[po][0],store[po][1],store[po][0],MY)){
			tem+=(MY-store[po][1]);
			addEdge(store[po][0],store[po][1],store[po][0],MY);
			digui(po+1);
			delEdge(store[po][0],store[po][1],store[po][0],MY);
			tem-=(MY-store[po][1]);
		}
		// 右
		if(allow(store[po][0],store[po][1],MX,store[po][1])){
			tem += (MX - store[po][0]);
			addEdge(store[po][0],store[po][1],MX,store[po][1]);
			digui(po+1);
			delEdge(store[po][0],store[po][1],MX,store[po][1]);
			tem -= (MX - store[po][0]);
		}
		// 下
		if(allow(store[po][0],store[po][1],store[po][0],0)){
			tem += store[po][1];
			addEdge(store[po][0],store[po][1],store[po][0],0);
			digui(po+1);
			delEdge(store[po][0],store[po][1],store[po][0],0);
			tem -= store[po][1];
		}
		// 左
		if(allow(store[po][0],store[po][1],0,store[po][1])){
			tem += store[po][0];
			addEdge(store[po][0],store[po][1],0,store[po][1]);
			digui(po+1);
			delEdge(store[po][0],store[po][1],0,store[po][1]);
			tem -= store[po][0];
		}
	}
	
}
void compute(){
	if(N == 0){
		ans = 0;
	}else{
		digui(0);
	}
}
void output(){
	printf("%d\n", ans);
}

void solve(){
	getin();
	compute();
	output();
}


int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		solve();
	}
}
