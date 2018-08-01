#include <stdio.h>
#include <queue>

struct Poi{
	int x,y,st;
};

int N,M,K;

Poi _oMap[2001][2001];

std::queue< Poi* > *que;

bool getin(){
	if(scanf("%d %d",&N,&M) != -1){
		que = new std::queue<Poi*>();
		scanf("%d",&K);
		int x,y;
		for(int i = 0;i < 2001;i++){
			for(int j = 0;j < 2001;j++){
				_oMap[i][j].st = -1;
				_oMap[i][j].x = i;
				_oMap[i][j].y = j;
			}
		}	
		for(int i = 0;i < K;i++){			
			scanf("%d %d",&x,&y);
			_oMap[x][y].st = 0;
			que->push(&_oMap[x][y]);

		}
		return true;
	}
	return false;
}

bool canput(int x,int y){
	if(1 <= x && x <= N && 1 <= y && y <= M && _oMap[x][y].st == -1){
		return true;
	}
	return false;
}
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void solve(){
	int max = 0;
	int minx = N+1;
	int miny = M+1;
	while(!que->empty()){
		int x,y,st;
		x = que->front()->x;
		y = que->front()->y;
		st = que->front()->st;
		//printf("check %d %d %d\n",x,y,st );
		if(st > max){
			max = st;
			minx = x;
			miny = y;	
		}else if(st == max){
			if(x < minx || (x == minx && y < miny)){
				minx = x;
				miny = y;
			}
		}
		
		for(int i = 0;i < 4;i++){
			int nex,ney,nest;
			nex = x+dx[i];
			ney = y+dy[i];
			nest = st+1;
			if(canput(nex,ney)){
				_oMap[nex][ney].st = nest;
				que->push(&_oMap[nex][ney]);
			}
		}
		que->pop();
	}
	printf("%d %d\n", minx,miny);
}

int main(){

	while(getin()){
		solve();
	}
}