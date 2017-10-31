#include <stdio.h>
#include <list>
using namespace std;
char* store;
char* answer;
int a;

int main(){
	int N;
	scanf("%d",&N);
	store = new char[N];
	for(int i = 0;i < N;i++){
		char ss[2];
		scanf("%s",ss);
		store[i] = ss[0];
	}
	answer = new char[N];
	a = 0;
	int j = 0;
	int begin = 0,end = N-1;
	int temp = N;
	while(temp--){
		char l = store[begin];
		char r = store[end];
		//printf("now%d%c %d%c\n", begin,l,end,r);
		if(l < r){
			answer[j++] = l; 
			begin++;
		}else if(l > r){
			answer[j++] = r;
			end--;
		}else{
			//printf("eq,then \n");
			int inb = begin+1;
			int ine = end-1;
			bool tag = false;
			for(;inb <= ine;inb++,ine--){
				//printf("now : %d%c  %d%c \n",inb, store[inb],ine,store[ine]);
				if(store[inb] < store[ine]){
					answer[j++] = l; 
					begin++;
					tag = true;
					break;
				}else if(store[inb] > store[ine]){
					answer[j++] = r;
					end--;
					tag = true;
					break;
				}
			}
			if(!tag){
				answer[j++] = l; 
				begin++;
			}

		}
		//printf("%c %c\n", l,r);
	}
	int ln = 0;
	for(int j = 0;j < N;j++){

		printf("%c", answer[j]);
		ln++;
		if(ln == 80){
			printf("\n");
			ln = 0;
		}
		//printf(" %d ", j);
	}
}