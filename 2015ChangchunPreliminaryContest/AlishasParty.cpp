#include <stdio.h>
#include <algorithm>
#include <vector>

int k,m,q;
char B[201]; // k friends
int v; // k
int t,p; // m times open
int n; // quiry
struct People{
	char name[201];
	int value;
	People(char *n,int v){
		int i = 0;
		for(;n[i] != '\0';i++){
			this->name[i] = n[i];
		}
		this->name[i] = '\0';
		this->value = v;
	}
};

std::vector<People> vec1;
std::vector<People*> vec2;
void output(){
	// printf("now:\n");
	// for(int i = 0;i < vec2.size();i++){
	// 	printf("%s ", vec2[i]->name);
	// }
	// printf("\n");
	People * temp = vec2[n-1];
	printf("%s",temp->name);
}
bool comp(People a,People b){
	return b.value < a.value;
}

void solve(){
	scanf("%d %d %d",&k,&m,&q);
	for(int i = 0;i < k;i++){
		scanf("%s %d",B,&v);
		vec1.push_back(*new People(B,v));
	}
	int start = 0;
	for(int i = 0;i < m;i++){
		scanf("%d %d",&t,&p);
		//printf("sort:%d~%d\n", start,t);
		std::stable_sort(vec1.begin() + start,vec1.begin() + t,comp);
		for(int i = 0;i < p;i++){
			vec2.push_back(&vec1[start+i]);
		}
		start += p;
	}
	for(int i = 0;i < q;i++){
		scanf("%d",&n);
		output();
		if(i == q-1){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}

int main(){
	int T;
	scanf("%d",&T);	
	for(int i = 0;i < T;i++){
		solve();
	}
}