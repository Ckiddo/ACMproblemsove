#include <stdio.h>
#include <vector>

int n,m;

struct Point{
	int number;
	std::vector<*Point> son;
	Point(int i){
		number = i;
	}
};

std::vector<Point> vec;


void getin(){
	scanf("%d %d",&n,&m);
	int s,t,c;
	for(int i =0 ;i <= n;i++){
		vec.push_back(*new Point(i));
	}
	for(int i = 0;i < m;i++){
		scanf("%d %d %d",&s,&t,&c);
		vec[s].son.push_back()
	}
}

void solve(){
	getin();
	compute();
	output();
}

int main(){
	solve();
}