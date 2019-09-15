#include <stdio.h>
#include <string.h>
char T[100001];
char S[100001];
int temp[100001];
int q;
int tl,sl;


void KMPPre(char* p, int KMP_next[]){
	int pLen=strlen(p);
	KMP_next[0]=-1;
	int k=-1;
	int j=0;
	while(j<pLen-1){
		if(k==-1||p[j]==p[k]){
			++j;
			++k;
			if(p[j]!=p[k])
				KMP_next[j]=k;
			else if(KMP_next[k]!=-1)
				KMP_next[j]=KMP_next[k];
			else
				KMP_next[j]=0;
		}
		else{
			k=KMP_next[k];
		}
	}
}


char* KmpSearch(char* s,int sLen,char* p,int pLen,int next[])
{
	int i=0;
	int j=0;
	while(i<sLen&&j<pLen){
		//①如果j=-1（代表又回到了P串的开头第一个字符，因为next[0]=-1），或者当前字符匹配成功（即S[i]==P[j]），都令i++，j++    
		if(j==-1||s[i]==p[j]){
			i++;
			j++;
		}
		else{
			//②如果j!=-1，且当前字符匹配失败，则令i不变(当前s串失配的地方)，j=next[j]    
			//next[j]即为j所对应的next值（其实就是和它含有相同前缀的地方，比如P为"AFHKAFOIU"，则next[6]=2,即第7个字符“O”的前两个字符"AF"(第五、六个字符)有相同前缀"AF"(第一、二个字符))
			j=next[j];
		}
	}
	if(j==pLen){
		return &s[i-j];
	}
	else{
		return NULL;
	}
}
int main(){
	scanf("%s",T);
	tl = strlen(T);
	scanf("%d", &q);
	for(int i = 0;i < q;i++){
		scanf("%s",S);
		sl = strlen(S);
		
		if(sl < tl){
			KMPPre(S,temp);
			if(KmpSearch(T,tl,S,sl,temp) != NULL){
				printf("my child!\n");
			}else{
				printf("oh, child!\n");
			}
		}else if(tl < sl){
			KMPPre(T,temp);
			if(KmpSearch(S,sl,T,tl,temp) != NULL){
				printf("my teacher!\n");
			}else{
				printf("senior!\n");
			}
		}else{
			KMPPre(T,temp);
			if(KmpSearch(S,sl,T,tl,temp) != NULL){
				printf("jntm!\n");
			}else{
				printf("friend!\n");
			}
		}
		
	}
}