#include <stdio.h>
#include <algorithm>


int caseNum = 0;

int _n,_m; // 点数和边数
struct Edge{
	int p1,p2,w;char col;
};

Edge edg[100];int e_sz = 0;

void insertEdge(int a,int b,int w,char col){
	edg[e_sz].p1 = a;
	edg[e_sz].p2 = b;
	edg[e_sz].w = w;
	edg[e_sz].col = col;
	e_sz++;
}
int ans[101][2];
void getin(){
	e_sz = 0;
	scanf("%d %d",&_n,&_m);
	for(int i = 0;i < _m;i++){
		int a,b,w;char c;
		scanf("%d %d %d %c",&a,&b,&w,&c);
		insertEdge(a,b,w,c);
	}
	for(int i = 0;i < 101;i++){
		ans[i][0] = -1;
		ans[i][1] = -1;
	}
}

bool vInTree[101];
bool eInTree[102];
int vInTreeNum = 0;
int eInTreeNum = 0;
int weights = 0;

int pointsInTree(){
	return vInTreeNum;
}

int edgesInTree(){
	return eInTreeNum;
}

void checkEdge(int chosed){
	printf("边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
}
void checkvInTreeSta(){
	for(int i = 1;i <= _n;i++){
		printf("%d inTree?%d\n", i,vInTree[i]);
	}
}

void choseFirstEdg(char co){
	std::fill(vInTree,vInTree+101,false);
	std::fill(eInTree,eInTree+101,false);
	vInTreeNum = 0;
	eInTreeNum = 0;
	weights = 0;
	int chosed = -1;
	for(int i = 0;i < _m;i++){
		if(edg[i].col == co){continue;}
		if(chosed == -1 || edg[i].w < edg[chosed].w){
			chosed = i;
		}
	}
	if(chosed == -1){
		vInTreeNum = _n;
		eInTreeNum = _m + 1;
		return;
	}
	vInTree[edg[chosed].p1] = true;
	vInTree[edg[chosed].p2] = true;
	eInTree[chosed] = true;
	vInTreeNum = 2;
	eInTreeNum = 1;
	weights += edg[chosed].w;
}

bool inTree(int i){
	if(vInTree[edg[i].p1] && vInTree[edg[i].p2]){
		return  true;
	}
	return false;
}
bool notInTree(int i){
	if(!vInTree[edg[i].p1] && !vInTree[edg[i].p2]){
		return true;
	}
	return false;
}
bool canConnctTree(int i){
	if((vInTree[edg[i].p1] && !vInTree[edg[i].p2]) || (!vInTree[edg[i].p1] && vInTree[edg[i].p2])){
		return true;
	}
	return false;
}
void addOtherEdg(char co){
	int chosed = -1;
	for(int i = 0;i < _m;i++){
		if(edg[i].col == co || inTree(i) || notInTree(i)){continue;}

		if(chosed == -1 || edg[i].w < edg[chosed].w){
			chosed = i;
		}
	}
	if(chosed == -1){
		vInTreeNum = _n;
		eInTreeNum = _m + 1;
		return;
	}
	vInTree[edg[chosed].p1] = true;
	vInTree[edg[chosed].p2] = true;
	eInTree[chosed] = true;
	vInTreeNum += 1;
	eInTreeNum += 1;
	weights += edg[chosed].w;
}



void addLastEdg(){
	int chosed = -1;
	for(int i = 0;i < _m;i++){
		if(eInTree[i]){continue;}
		if(chosed == -1 || edg[i].w < edg[chosed].w){
			chosed = i;
		}
	}
	eInTree[chosed] = true;
	eInTreeNum++;
	weights += edg[chosed].w;
}

void compute(char co){
	choseFirstEdg(co);
	while(pointsInTree() < _n){
		addOtherEdg(co);
	}
	if(co == 'B'){
		ans[edgesInTree()][0] = weights;
	}else{
		ans[edgesInTree()][1] = weights;
	}

	while(edgesInTree() < _m){
		addLastEdg();
		if(co == 'B'){
			ans[edgesInTree()][0] = weights;
		}else{
			ans[edgesInTree()][1] = weights;
		}
	}
}



void output(){
	printf("Case #%d\n", caseNum);
	for(int i = 1;i <= _m;i++){
		if(ans[i][0] != -1 &&ans[i][1] != -1 ){
			printf("%d\n", std::min(ans[i][0],ans[i][1]));
		}else{
			printf("%d\n", std::max(ans[i][0],ans[i][1]));
		}
	}
}

void solve(){
	getin();
	compute('B');
	compute('R');
	output();
}

int main(){
	int T = 0;
	scanf("%d",&T);
	for(int i = 1;i <= T;i++){
		caseNum = i;
		solve();
	}
}