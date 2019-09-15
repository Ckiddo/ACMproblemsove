#include <stdio.h>
#include <set>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
int n,q;
int z,x;

struct {
	bool operator()(pair<int, int> a, int b){
		return a.first < b;
	}
}myCmp;

void show(set<pair<int, int> > & myset, int x){
	cout<<lower_bound(myset.begin(), myset.end(),x,myCmp)->first;
}
void oper(set<pair<int, int> > & myset, int x){
	
}


int main(){
	set<pair<int, int> > myset;
	scanf("%d %d", &n, &q);
	myset.insert(make_pair(1,n+1));
	for(int i = 0;i < q;i++){
		scanf("%d %d",&z, &x);
		if(z-1){
			show(myset,x);
		}else{
			oper(myset,x);
		}
	}
}