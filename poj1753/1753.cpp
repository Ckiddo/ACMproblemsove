#include <stdio.h>

char maps[4][4];
bool map[4][4];


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void change(int x,int y	){
	map[x][y] = !map[x][y];
	for(int i = 0;i < 4;i++){
		if((0 <=x + dx[i])&&(x + dx[i] < 4)&&(0 <= y + dy[i])&&( y + dy[i] < 4)){
			map[x + dx[i]][y + dy[i]] = !map[x + dx[i]][y + dy[i]];
		}
	}
}

bool found(){
	bool temp = map[0][0];
	for(int i =0;i < 4;i++){
		for(int j = 0;j  <4 ;j++){
			if(temp != map[i][j]){
				return false;
			}
		}
	}
	return true;
}

void show(){
	for(int i = 0;i < 4;i++){
		for(int j = 0;j <4;j++){
			printf("%d",(int)map[i][j] );
		}
		printf("\n");
	}
}
int step;
int answer;
bool founded;
void dfs(int x,int y,int s){
	// printf("dfs: %d %d %d\n", x,y,s);
	
	// show();
	if(found()){
		if(s < answer){
			answer = s;
		}
		return;
	}
	if((x == 4) || founded){return;}
	//nx  ny
	int nx = x;
	int ny = y + 1; if(ny == 4){nx++;ny = 0;}
	// dnc
	dfs(nx,ny,s);
	// c
	change(x,y);
	dfs(nx,ny,s+1);
	change(x,y);
}

int main(){
	step = 0;
	answer = 20;
	founded = false;
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			maps[i][j] = getchar();
			if(maps[i][j] == 'w'){
				map[i][j] = true;
			}else{
				map[i][j] = false;
			}
		}
		getchar();
	}
	dfs(0,0,0);
	// show();
	if(answer != 20){
		printf("%d\n", answer);
	}else{
		printf("Impossible\n");
	}
	// change(3,3);
	// show();
}