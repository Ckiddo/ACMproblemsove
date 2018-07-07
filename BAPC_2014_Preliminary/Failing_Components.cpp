#include <stdio.h>
#include <vector>

struct Node{
	int num;
	bool state;
	std::vector<int> son;
	Node(int n){
		num = n;
	}
};
std::vector<Node> vec;


int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		int n,d,c;
		scanf("%d %d %d" ,&n,&d,&c);
		for(int i = 0;i <= n;i++){
			vec.push_back(*new Node(i));
		}
		for(int dd = 0;dd < d;dd++){
			int a,b,s;
			scanf("%d %d %d",&a,&b,&s);
			vec[b].son
		} 
	}
}