#include <stdio.h>
#include <vector>

/*
10 3
0
1
2
3
4
5
6
7
8
9
*/


int n,k;
struct Machine{
	int hold;
	int* gezi;
	Machine(int ho,int re){
		hold = ho;
		gezi = new int[hold];
		gezi[0] = re;
		for(int i =1;i < hold;i++){
			gezi[i] = -2000;
		}
	}
	bool add(int req){
		for(int i = 0;i < hold;i++){
			if(req-gezi[i] >= 1000){
				gezi[i] = req;
				return true;
			}
		}
		return false;
	}
};

std::vector<Machine> vec;




void add(int req){
	for(int i = 0;i < vec.size();i++){
		if(vec[i].add(req)){
			return;
		}
	}
	vec.push_back(*new Machine(k,req));
}

void getin(){
	scanf("%d %d",&n,&k);
	int t;
	for(int i =0;i < n;i++){
		scanf("%d",&t);
		add(t);
	}
}

void compute(){

}

void output(){
	printf("%ld\n", vec.size());
}

void solve(){
	getin();
	compute();
	output();
}
int main(){

	solve();
}