#include <stdio.h>
#include<string.h>
#include <vector>

int words,height,width;
char wordsmap[33][33];
int markmap[33][33];
char wordsStore[256][33];
bool printed;
int answer;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

void showWordsMap(){
	if(answer == 0){
		printf("no solution\n");
		return;
	}else if (answer >= 2){
		printf("ambiguous\n");
		return;
	}
	for(int h = 0;h < height;h++){
		for(int w = 0;w < width;w++){
			if(markmap[h][w] == 0){
				printf("%c", wordsmap[h][w]);
				printed = true;
			}
		}
	}
	if(printed == false){
		printf("empty solution\n");
	}else{
		printf("\n");
	}
}

void showWord(char* word){
	//printf("%d\n", strlen(word));
	for(int i = 0;word[i] != '\0';i++){
		printf("%c", word[i]);
	}
}

bool huiwen(char* word){
	int length = strlen(word);
	for(int i = 0;i < length / 2;i++){
		if(word[i] == word[length - 1 - i]){

		}else{
			return false;
		}
	}
	return true;
}

class Line{
public:
	
	int sh,sw,eh,ew;
	Line(int a,int b,int c,int d){
		sh = a;
		sw = b;
		eh = c;
		ew = d;
	}
};

std::vector<Line> vec;

bool exits(int a,int b,int c,int d){
	for(int i =0 ;i < vec.size();i++){
		if(vec[i].sh == c && vec[i].sw == d && vec[i].eh == a && vec[i].ew == b){
			return true;
		}
	}
	return false;
}

void add(int a,int b,int c,int d){
	vec.push_back(*new Line(a,b,c,d));
}

int bfs(int h,int w,char* word){
	int length = (int)strlen(word);
	int count = 0;
	
	for(int i = 0;i < 8;i++){
		bool tag = true;
		int hh = h;
		int ww = w;
		for(int l = 1;l < length;l++,hh = hh+dx[i],ww = ww+dy[i]){
			if( (0<=hh+dx[i] && hh + dx[i] < height && 0<= ww + dy[i] && ww+dy[i] < width)&& (word[l] == wordsmap[hh+dx[i]][ww+dy[i]])){
				continue;
			}else{
				tag = false;
				break;
			}
		}
		if(tag){
			int starth = h;
			int startw = w;
			int endh = h;
			int endw = w;
			hh = h;
			ww = w;
			for(int l = 0;l < length;l++,hh=hh+dx[i],ww = ww+dy[i]){
				
				markmap[hh][ww] =1;
				endh = hh;
				endw = ww;
			}

			if(huiwen(word)){
				if(exits(starth,startw,endh,endw)){ //founded
					continue;
				}else{
					add(starth,startw,endh,endw);
				}
			}
			count++;
			//printf(":found it on x:%dy:%d to x:%dy:%d\n", starth,startw,endh,endw);
		}
	}
	return count;
}

int search(char* word){
	int count = 0;
	int length = strlen(word);
	for(int h = 0;h < height;h++){
		for(int w = 0;w < width;w++){
			if(length == 1&& word[0] == wordsmap[h][w]){
				count++;
				//printf(":%s is only a letter,founded it on %d %d\n", word,h,w);
			}else if(word[0] == wordsmap[h][w]){
				count+=bfs(h,w,word);
			}
		}
	}
	return count;
}

void deleteAllWords(){
	for(int wo = 0;wo < words;wo++){
		// search words[0]
		//printf(":read to search%s\n", wordsStore[wo]);
		int searchNum = search(wordsStore[wo]);
		//printf(":search %s end,found %d\n", wordsStore[wo],searchNum);
		if (searchNum == 0){
			answer = 0;
			return;
		}else if (searchNum >= 2){
			answer = 2;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		answer = -1;
		printed = false;
		scanf("%d %d %d",&words,&height,&width);
		for(int h = 0;h < height;h++){
			scanf("%s",wordsmap[h]);
			for(int w = 0;w < width;w++){
				markmap[h][w] = 0;
			}
		}
		for(int wo = 0;wo < words;wo++){
			scanf("%s",wordsStore[wo]);
			//showWord(wordsStore[wo]);
		}
		deleteAllWords();
		
		showWordsMap();

	}
}