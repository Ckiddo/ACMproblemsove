#include <stdio.h>
#include <queue>
#include <vector>
/*
2 6
 _ _ _ _ _ _ 
|  _ _ _ _ _|
|_ _ _ _ _ _|
5
1 5
1 1
1 6
1 1
1 5


5 5
 _ _ _ _ _ 
|_ _  |_  |
|  _| |  _|
| |_   _| |
|    _ _  |
|_|_ _ _|_|
7
4 4
1 4
3 1
4 5
1 2
2 2
5 4
*/
struct Node{
	Node* father;
	int x,y;
	int height;
	int mark;
	std::vector<Node*> son;
};

long long _dis;
int h,w;
int m;
char _oriMap[1001][2002];
Node _map[1001][1001];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
bool cango(int x1,int y1,int x2,int y2){
	if(x2 <= 0 || x2 > h || y2 <= 0 || y2 > w){
		return false;
	}
	if(x1 == x2){
		if(y2 > y1){
			// right
			//printf("right\n");
			if(_oriMap[x1][y1*2] == '|'){
				return false;
			}
		}else{
			// left
			//printf("left\n");
			if(_oriMap[x1][y1*2-2] == '|'){
				return false;
			}
		}
	}else if(x1 > x2){
		// up
		//printf("up\n");
		if(_oriMap[x2][y2*2-1] == '_'){
			return false;
		}
	}else if(x1 < x2){
		// down
		//printf("down\n");
		if(_oriMap[x1][y1*2-1] == '_'){
			return false;
		}
	}
	if(_map[x2][y2].height == -1){
		return true;
	}else{
		return false;
	}
}

void buildTree(){
	std::queue<Node*> que;
	for(int i = 1;i <=1000;i++){
		for(int j = 1;j <=1000;j++){
			_map[i][j].x = i;
			_map[i][j].y = j;
			_map[i][j].height = -1;
			_map[i][j].mark = 0;
		}
	}
	_map[1][1].height = 0;
	_map[1][1].father = NULL;
	que.push(&_map[1][1]);
	while(!que.empty()){
		int stx,sty;
		int h;
		stx = que.front()->x;
		sty = que.front()->y;
		h = que.front()->height;
		for(int i = 0;i < 4;i++){

			if(cango(stx,sty,stx+dx[i],sty+dy[i])){
				_map[stx+dx[i]][sty+dy[i]].height = h+1;
				que.push(&_map[stx+dx[i]][sty+dy[i]]);
				_map[stx][sty].son.push_back(&_map[stx+dx[i]][sty+dy[i]]);
				_map[stx+dx[i]][sty+dy[i]].father = &_map[stx][sty];
			}
		}
		que.pop();
	}
}

void getinBuildTree(){
	scanf("%d %d",&h,&w);
	getchar();
	for(int i = 0;i < h+1;i++){
		for(int j = 0;j < w*2+1;j++){
			_oriMap[i][j] = getchar();
		}
		getchar();
	}
	buildTree();
}
void checkfather(int x,int y){
	int xx = x,yy = y;
	int newx,newy;
	while(_map[xx][yy].father != NULL){
		
		newx = _map[xx][yy].father->x;
		newy = _map[xx][yy].father->y;
		printf("%d %d's father:%d %d \n", xx,yy,newx,newy);
		printf("%d %d's height:%d\n", xx,yy,_map[xx][yy].height);
		xx = newx;
		yy = newy;
	}
}
long long computedis(int x1,int y1,int x2,int y2){
	int qq1 = _map[x1][y1].height;
	//printf("%d %dheight:%d\n", x1,y1,qq1);
	int qq2;
	int qq3 = _map[x2][y2].height;
	//printf("%d %dheight:%d\n",x2,y2,qq3 );
	int xx = x1,yy = y1;
	int newx,newy;
	_map[xx][yy].mark = 1;
	while(_map[xx][yy].father != NULL){
		
		newx = _map[xx][yy].father->x;
		newy = _map[xx][yy].father->y;
		_map[newx][newy].mark = 1;
		//printf("%d %dheight:%d 's father:%d %d \n", xx,yy,_map[xx][yy].height,newx,newy);
		xx = newx;
		yy = newy;
	}
	//printf("%d %d's father is null:%d\n", xx,yy,_map[xx][yy].father==NULL);
	int xxx = x2,yyy = y2;
	int newxx,newyy;
	if(_map[xxx][yyy].mark == 1){
		qq2 = _map[xxx][yyy].height;
		//printf("%d %dheight:%d\n", xxx,yyy,qq2);
		xx = x1,yy = y1;
		_map[xx][yy].mark = 0;
		while(_map[xx][yy].father != NULL){
			newx = _map[xx][yy].father->x;
			newy = _map[xx][yy].father->y;
			_map[newx][newy].mark = 0;
			//printf("%d %d's father:%d %d \n", xx,yy,newx,newy);
			xx = newx;
			yy = newy;
		}
		return (qq3-qq2)+(qq1 - qq2);
	}
	while(_map[xxx][yyy].father != NULL){
		
		newxx = _map[xxx][yyy].father->x;
		newyy = _map[xxx][yyy].father->y;
		//printf("%d %dheight:%d 's father:%d %d \n", xxx,yyy,_map[xxx][yyy].height,newxx,newyy);
		if(_map[newxx][newyy].mark == 1){
			qq2 = _map[newxx][newyy].height;
			//printf("%d %dheight:%d\n", newxx,newyy,qq2);
			xx = x1,yy = y1;
			_map[xx][yy].mark = 0;
			while(_map[xx][yy].father != NULL){
				newx = _map[xx][yy].father->x;
				newy = _map[xx][yy].father->y;
				_map[newx][newy].mark = 0;

				//printf("%d %d's father:%d %d \n", xx,yy,newx,newy);
				xx = newx;
				yy = newy;
			}
			return (qq3-qq2)+(qq1 - qq2);
		}
		//printf("%d %d's father:%d %d \n", xx,yy,newx,newy);
		xxx = newxx;
		yyy = newyy;
	}
	return 0;
}

void compute(){
	_dis = 0;
	scanf("%d",&m);

	int stx,sty;
	int xx,yy;
	scanf("%d %d",&stx,&sty);
	//printf("got %d %d\n", stx,sty);
	for(int i = 1;i < m;i++){
		scanf("%d %d",&xx,&yy);
		//printf("got %d %d\n",xx,yy );
		int tem =computedis(stx,sty,xx,yy);
		_dis +=tem;
		//printf("%d %d %d %d is %d\n",stx,sty,xx,yy, tem);
		stx = xx;
		sty = yy;
	}
}

void output(){
	printf("%lld\n", _dis);
}
void solve(){
	getinBuildTree();
	//printf("gotTree\n");
	compute();
	//printf("computed\n");
	output();
}
int main(){
	solve();
}