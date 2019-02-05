#include <stdio.h>
#include <algorithm>
#include <vector>

#ifndef stampNum
#define stampNum 100
#endif


int values[stampNum];int values_num = 0;
int costom[10000];int costom_num = 0;


void showvalues(){
    for(int i = 0;i < values_num;i++){
        printf("%d ",values[i]);
    }
    printf("\n");
}
void showcostom(){
    for(int i = 0;i < costom_num;i++){
        printf("%d ",costom[i]);
    }
    printf("\n");
}

int project[stampNum];int kinds,numbers,maxvalue;
int ans_project[stampNum];int ans_kinds,ans_numbers,ans_maxvalue;int ans_mark;
void clearProject(){
    for(int i = 0;i < values_num;i++){
        project[i] = 0;
        ans_project[i] = 0;
    }
    kinds = 0;
    ans_kinds = 0;
    numbers = 0;
    ans_numbers = 100;
    maxvalue = 0;
    ans_mark = 1;
}
void showProject(){
    printf("Project: ");
    for(int i = 0;i<values_num;i++){
        printf("%d ",project[i]);
    }
    printf("\nans_kinds:%d, ans_numbers:%d, ans_maxvalue:%d\n",ans_kinds,ans_numbers,ans_maxvalue);
    printf("kinds:%d, numbers:%d, maxvalue:%d",kinds,numbers,maxvalue);
    printf("\n");
}
int cosi;
bool projectCorrect(){
    int sum = 0;
    kinds = 0;
    numbers = 0;
    maxvalue = 0;
    for(int i = 0;i < values_num;i++){
        sum += project[i] * values[i];
        if(project[i] > 0){
            kinds += 1;
            numbers += project[i];
            if(values[i] > maxvalue){
                maxvalue = values[i];
            }
        }
    }
    return sum == costom[cosi];
}
//int ans_project[stampNum];int ans_kinds,ans_numbers,ans_maxvalue;int ans_mark;
//
void copyProject(){
    for(int i = 0;i < values_num;i++){
        ans_project[i] = project[i];
    }
    ans_kinds = kinds;
    ans_numbers = numbers;
    ans_maxvalue = maxvalue;
    ans_mark = 0;
}
void addProject(){
    if(kinds > ans_kinds){
        copyProject();
    }else if(kinds == ans_kinds){
        if(numbers < ans_numbers){
            copyProject();
        }else if(numbers == ans_numbers){
            if(maxvalue > ans_maxvalue){
                copyProject();
            }else if(maxvalue == ans_maxvalue){
                ans_mark = 2;
            }
        }
    }
}
void permutation(int pos,int n,int remain){

    if(n >= 5 || remain < 0){
        return;
    }else{
        if(projectCorrect()){
            // showProject();
            addProject();
        }
    }

    for(int i = pos;i < values_num;i++){

        for(int j = remain;j>0;j--){
            project[i] += j;
            permutation(i+1,n+1,remain-j);
            project[i] -= j;
        }
    }
}
void printAns(){
    printf("%d ",costom[cosi]);
    if(ans_mark == 0){
        printf("(%d):",ans_kinds);
        for(int i = 0;i < values_num;i++){
            for(int j = 0;j < ans_project[i];j++){
                printf(" %d",values[i]);
            }
        }
        printf("\n");
    }else if(ans_mark == 1){
        printf("---- none\n");
    }else if(ans_mark == 2){
        printf("(%d): tie\n",ans_kinds);
    }else{
        printf("\n");
    }
}
void solve(){
    for(cosi = 0;cosi < costom_num;cosi++){
        clearProject();
        permutation(0,0,4);
        printAns();
    }
}


int main(){
    int val;
    int cos;
    while(scanf("%d",&val) != EOF){
        while(val != 0){
            values[values_num++] = val;
            scanf("%d",&val);
        }
        std::sort(values,values+values_num);
        scanf("%d",&cos);
        while(cos != 0){
            costom[costom_num++] = cos;
            scanf("%d",&cos);
        }
        solve();
        val = 0;
        cos = 0;
        values_num = 0;
        costom_num = 0;
    }
}
