#include <stdio.h>

char store[301];
char per[3] = {'P','E','R'};
void solve(){
    scanf("%s",store);
    int count = 0;
    for(int i = 0;store[i] != '\0';i++){
        if(store[i] != per[i%3] ){
            count++;
        }
    }
    printf("%d",count);
}
int main(){
    solve();
}
