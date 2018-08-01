#include <stdio.h>
#include <vector>
#include <queue>

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


int h,w;
char _oriMap[1001][2002];
char _map[1001][1001];
int m;
int x,y;
int points[10000][2];
long long _dis;

void getin(){
	for(int i = 0;i < 1001;i++){
		for(int j = 0;j < 1001;j++){
			_map[i][j] = -1;
		}
	}
	scanf("%d %d",&h,&w);
	char c;
	getchar();
	for(int i = 0;i < h+1;i++){
		for(int j = 0;j < 2*w +1;j++){
			c = getchar();
			_oriMap[i][j] = c;
		}
		getchar();

	}

	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		scanf("%d %d",&x,&y);
		points[i][0] = x;
		points[i][1] = y;
	}

}

struct Grad{
	int x,y;
	long long step;
	Grad(int xx,int yy,long long st){
		x = xx;
		y = yy;
		step = st;
	}
};

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
	if(_map[x2][y2] == -1){
		return true;
	}else{
		return false;
	}
}

long long getdistance(int x1,int y1,int x2,int y2){
	for(int i = 0;i < 1001;i++){
		for(int j = 0;j < 1001;j++){
			_map[i][j] = -1;
		}
	}
	std::queue<Grad> que;
	que.push(*new Grad(x1,y1,0));
	while(!que.empty()){
		int x,y;
		long long st;

		x = que.front().x;
		y = que.front().y;
		st = que.front().step;

		for(int i = 0;i < 4;i++){
			if(cango(x,y,x+dx[i],y+dy[i])){
				if(x+dx[i] == x2 && y+dy[i] == y2){
					//printf("from %d %d to %d %d need %lld\n",x1,y1,x2,y2,st+1 );
					return st + 1;
				}
				que.push(*new Grad(x+dx[i],y+dy[i],st + 1));
			}
		}
		que.pop();
	}
	//printf("not found route\n");
	return -1;

}

void compute(){
	int stx,sty;
	stx = points[0][0];
	sty = points[0][1];
	_dis = 0;
	for(int i = 1;i < m;i++){
		long long te = getdistance(stx,sty,points[i][0],points[i][1]);
		_dis += te;
		stx = points[i][0];
		sty = points[i][1];
	}

}

void output(){
	printf("%lld\n", _dis);
}

void solve(){
	getin();
	compute();
	output();
}


int main(){
	solve();
}