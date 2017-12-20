#include <stdio.h>
#include <stack>
#include <math.h>
using namespace std;

char express_stand[200];int n_stand; // 标准答案
int answer_standard;
char express_student[200]; int n_student;// 学生答案
int answer_student;

int  getExpression(char* ss){
	char c;
	int size = 0;
	while((c = getchar()) != '\n'){
		ss[size] = c;
		size++;
	}
	ss[size] = ')';
	size++;
	ss[size] = '\0';
	return size;
}

int cacula(int l,char c,int r){
	if(c == '+'){
		return l+r;
	}else if(c == '-'){
		return l-r;
	}else if(c == '*'){
		return l*r;
	}else if(c== '^'){
		return (int)(pow(l,r));
	}
	return 0X7FFFFFFF;
}
int deal(char* exp,int n){
	char newexpress[300];int nnp = 0;
	newexpress[nnp] = '(';
	for(int i = 0;i < n;i++){
		if('0' <= exp[i] && exp[i] <='9'){
			if(('a' <= newexpress[nnp] && newexpress[nnp] <= 'z') || newexpress[nnp] == ' ' || newexpress[nnp] == ')'){
				newexpress[nnp+1] = '*';nnp++;
				newexpress[nnp+1] = exp[i];nnp++;
			}else{
				newexpress[nnp+1] = exp[i];nnp++;
			}
		}else if('a' <= exp[i] && exp[i] <='z'){
			if(newexpress[nnp] == '+' || newexpress[nnp] == '(' || newexpress[nnp] == '^' || newexpress[nnp] == '-'){
				newexpress[nnp+1] = exp[i];nnp++;
			}else{
				newexpress[nnp+1] = '*';nnp++;		
				newexpress[nnp+1] = exp[i];nnp++;
			}
		}else if(exp[i] == ' '){
			if(newexpress[nnp] == ' ' || newexpress[nnp] == '+' || newexpress[nnp] == '(' || newexpress[nnp] == '^' || newexpress[nnp] == '-'){
				continue;
			}else{
				newexpress[nnp+1] = exp[i];nnp++;
			}
		}else if(exp[i] == '+' || exp[i] == '-' || exp[i] == ')' || exp[i] == '^'){
			newexpress[nnp+1] = exp[i];nnp++;
		}else if(exp[i] == '('){
			if(newexpress[nnp] == '+' || newexpress[nnp] == '(' || newexpress[nnp] == '^' || newexpress[nnp] == '-'){
				newexpress[nnp+1] = exp[i];nnp++;
			}else{
				newexpress[nnp+1] = '*';nnp++;
				newexpress[nnp+1] = exp[i];nnp++;
			}
		}else{
			continue;
		}
	}
	//newexpress[nnp+1] = ')';nnp++;
	newexpress[nnp+1] = '\0';nnp++;
	for(int i = 0;i < nnp;i++){
		exp[i] = newexpress[i];
	}
	return nnp;
}
int clp[] = {16,80,72,82,47,
			52,49,17,22,65,
			73,98,49,43,66,
			81,14,41,8,93,
			47,21,12,73,10
			,27};
int getanswer(char* ss,int n){
	stack<int> opnd;
	stack<char> optr;
	for(int i = 0;i < n;){
		if(ss[i] == ' '){
			i++;
			continue;
		}
		if(('0'<=ss[i] && ss[i] <= '9' )){
			//read number;
			bool count = false;
			float num = ss[i]- '0';
			int numc = 1;
			for(i++;(ss[i]<='9' && ss[i] >='0') || ss[i] == '.';i++){
				if(count){
					numc = numc*10;
				}
				if(ss[i] != '.'){
					num = num*10 + ss[i] - '0';
				}else{
					count = true;
				}
			}
			opnd.push(num);
		}else if('a'<=ss[i] && ss[i] <= 'z' ){
			opnd.push(clp[ss[i]-'a']);
			i++;
		}else{
			if( (ss[i] == '(') || 
				((optr.top() == '+' || optr.top() == '-' || optr.top() == '(') && (ss[i] == '*' || ss[i] == '/')) ||
				((optr.top() == '(') && (ss[i] != '(' && ss[i] != ')')) || 
				(optr.top() == '^' && ss[i] == '(') || 
				(ss[i] == '^' && optr.top() != '^')){ // 栈顶优先级低
				optr.push(ss[i]);
				i++;
				
			}else if(((optr.top() == '*' || optr.top() == '/') && ss[i] != '(')||
						((optr.top() == '+' || optr.top() == '-') && (ss[i] == '+' || ss[i] == '-' || ss[i] == ')'))|| 
						(optr.top() == '^' && (ss[i] != '(')) || 
						(ss[i] == '^' && optr.top() == '^')){ // 栈顶优先级高
				float r = opnd.top();opnd.pop();
				float l = opnd.top();opnd.pop();
				char c = optr.top();optr.pop();
				char cc[2];
				cc[0] = c;
				cc[1] = '\0';
				opnd.push(cacula(l,c,r));
			}else if(optr.top() == '(' && ss[i] == ')'){ // 相等
				optr.pop();i++;
			}else{
				i++;
			}
		}
	}
	return opnd.top();
}

int main(){
	n_stand = getExpression(express_stand);
	while(n_stand != 1 && express_stand[0] != '.'){
		n_stand = deal(express_stand,n_stand);
		//printf("express_stand:%s\n", express_stand);
		answer_standard = getanswer(express_stand,n_stand);
		printf("answer_standard:%d\n", answer_standard);
		printf("%s\n", express_stand);
		n_student = getExpression(express_student);
		while(n_student != 1 && express_student[0] != '.'){
			n_student = deal(express_student,n_student);
			printf("express_student:%s length:%d\n",express_student, n_student);
			answer_student = getanswer(express_student,n_student);
			printf("answer_student:%d\n", answer_student);
			if(answer_student == answer_standard){
				printf("yes\n");
			}else{
				printf("no\n");
			}
			n_student = getExpression(express_student);
			//printf("getExpression:%s length:%d\n",express_student,n_student);
		}
		printf(".\n");
		n_stand = getExpression(express_stand);
	}


}