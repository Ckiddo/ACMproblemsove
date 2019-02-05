#include <stdio.h>
#include <algorithm>


struct Edge{
	int p1,p2,w;
	char col;
};
int _n,_m;
Edge edg[100];bool usedEdg[101];int e_sz;
int W[101][2];

int caseNum = 0;

bool inTree[101];
void addEdg(int a,int b,int ww,char c){
	edg[e_sz].p1 = std::min(a,b);
	edg[e_sz].p2 = std::max(a,b);	
	edg[e_sz].w = ww;
	edg[e_sz].col = c;
	e_sz++;
}

void getin(){
	e_sz = 0;
	std::fill(inTree,inTree+101,false);
	scanf("%d %d",&_n,&_m);
	for(int i = 0;i < _m;i++){
		int a,b,w;char col;
		scanf("%d %d %d %c",&a,&b,&w,&col);
		addEdg(a,b,w,col);
	}


}
bool inLianTong(int i){
	if((inTree[edg[i].p1])&&(inTree[edg[i].p2])){
		return true;
	}
	return false;
}
bool canConneTr(int i){
	if((inTree[edg[i].p1])||(inTree[edg[i].p2])){
		return true;
	}
	return false;
}

void checkInTree(){
	for(int i = 1;i <= _n;i++){
		printf("%d in tree?%d\n", i,inTree[i]);
	}
}
void computeRG(){
	// 先选一条初始边：
	for(int i = 1;i <= _m;i++){W[i][0] = -1;}
	int chosed = -1;
	int treeWeight = 0;
	int edgCount = 0;
	std::fill(usedEdg,usedEdg + 101,false);
	std::fill(inTree,inTree + 101,false);
	for(int i = 0;i < e_sz;i++){
		if(edg[i].col == 'B'){
			//printf("边号：%d 为红,跳过 a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
			continue;
		}
		if(chosed == -1 || (edg[i].w < edg[chosed].w)){
			//printf("RG选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
			chosed = i;
		}
	}
	if(chosed == -1){
		return;
	}
	printf("RG最终选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
	usedEdg[chosed] = true;
	inTree[edg[chosed].p1] = true;
	inTree[edg[chosed].p2] = true;

	treeWeight += edg[chosed].w;
	edgCount += 1;
	int v = 2;
	while(v < _n){
		chosed = -1;
		for(int i = 0;i < e_sz;i++){
			if(edg[i].col == 'B' || inLianTong(i) || !canConneTr(i))continue;
			if(chosed == -1 ||(edg[i].w < edg[chosed].w)){
				chosed = i;
			}
		}
		if(chosed == -1){
			return;
		}
		printf("RG选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
		//checkInTree();
		usedEdg[chosed] = true;
		inTree[edg[chosed].p1] = true;
		inTree[edg[chosed].p2] = true;
		treeWeight += edg[chosed].w;
		edgCount += 1;
		v++;
	}

	W[edgCount][0] = treeWeight;
	for(int i = edgCount + 1;i <= _m;i++){
		chosed = -1;
		for(int i = 0;i < _m;i++){
			if(usedEdg[i]){
				//printf("%d 用过了\n", i);
				continue;
			}
			if(chosed == -1 ||edg[i].w < edg[chosed].w){
				chosed = i;
			}
		}
		usedEdg[chosed] = true;
		printf("RG结尾选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
		W[i][0] = W[i-1][0] + edg[chosed].w;
	}
}

void computeBG(){
	// 先选一条初始边：
	for(int i = 1;i <= _m;i++){W[i][0] = -1;}
	int chosed = -1;
	int treeWeight = 0;
	int edgCount = 0;
	std::fill(usedEdg,usedEdg + 101,false);
	std::fill(inTree,inTree + 101,false);
	for(int i = 0;i < e_sz;i++){
		if(edg[i].col == 'R'){
			//printf("边号：%d 为红,跳过 a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
			continue;
		}
		if(chosed == -1 || (edg[i].w < edg[chosed].w)){
			//printf("RG选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
			chosed = i;
		}
	}
	if(chosed == -1){
		return;
	}
	printf("BG选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
	usedEdg[chosed] = true;
	inTree[edg[chosed].p1] = true;
	inTree[edg[chosed].p2] = true;

	treeWeight += edg[chosed].w;
	edgCount += 1;
	int v = 2;
	while(v < _n){
		chosed = -1;
		for(int i = 0;i < e_sz;i++){
			if(edg[i].col == 'R' || inLianTong(i) || !canConneTr(i))continue;
			if(chosed == -1 || (edg[i].w < edg[chosed].w)){
				// checkInTree();
				// if(canConneTr(i)){
				// 	printf("%d，的两个点为：%d %d能连\n", i,edg[i].p1,edg[i].p2);
				// }
				chosed = i;
			}
		}
		if(chosed == -1){
			return;
		}
		printf("BG选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
		//checkInTree();
		usedEdg[chosed] = true;
		inTree[edg[chosed].p1] = true;
		inTree[edg[chosed].p2] = true;
		treeWeight += edg[chosed].w;
		edgCount += 1;
		v++;
	}
	W[edgCount][1] = treeWeight;
	for(int i = edgCount + 1;i <= _m;i++){
		chosed = -1;
		for(int i = 0;i < _m;i++){
			if(usedEdg[i]){
				//printf("%d 用过了\n", i);
				continue;
			}
			if(chosed == -1 ||edg[i].w < edg[chosed].w){
				chosed = i;
			}
		}
		usedEdg[chosed] = true;
		printf("BG结尾选择边号：%d a:%d b:%d w:%d col:%c\n", chosed,edg[chosed].p1,edg[chosed].p2,edg[chosed].w,edg[chosed].col);
		W[i][1] = W[i-1][1] + edg[chosed].w;
	}
}

void output1(){
	for(int i = 1;i <= _m;i++){
		printf("%d ", W[i][0]);
	}
	printf("\n");
	for(int i = 1;i <= _m;i++){
		printf("%d ", W[i][1]);
	}
	printf("\n");
}
void output2(){
	printf("Case #%d:\n", caseNum);
	for(int i = 1;i <= _m;i++){
		if(W[i][0] != -1 &&W[i][1] != -1 ){
			printf("%d\n", std::min(W[i][0],W[i][1]));
		}else{
			printf("%d\n", std::max(W[i][0],W[i][1]));
		}
		
	}
}

void solve(){
	getin();
	computeRG();
	computeBG();
	output2();
}


int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		caseNum = i+1;
		solve();
	}
}