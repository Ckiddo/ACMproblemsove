#include <stdio.h>

#ifndef MAX_N
#define MAX_N 100
#endif

struct node{
    int val;
    node *lch, *rch;
};

node* insert(node *p, int x){
    if(p == NULL){
        node *q = new node();
        q->val = x;
        q->lch = NULL;
        q->rch = NULL;
        return q;
    }else{
        if(x < p->val) p->lch = insert(p->lch,x);
        else p->rch = insert(p->rch,x);
        return p;
    }
}

bool find(node *p,int x){
    if(p == NULL)return false;
    else if(x == p->val) return true;
    else if (x < p->val) return find(p->lch,x);
    else return find(p->rch,x);
}

node* remove(node* p,int x){
    if(p == NULL){
        return NULL;
    }else if(x < p->val){
        return p->lch = remove(p->lch,x);
    }else if(p->val < x){
        return p->rch = remove(p->rch,x);
    }else if(p->lch == NULL){
        node *q = p->rch;
        delete p;
        return q;
    }else if(p->lch->rch ==NULL){
        node* q = p->lch;
        q->rch = p->rch;
        delete p;
        return q;
    }else{
        node *q;
        for(q = p->lch;q->rch->rch != NULL;q = q->rch);
        node *r = q->rch;
        q->rch = r->lch;
        r->lch = p->lch;
        delete p;
        return r;
    }
}
void bianLi1(node* p){
    // 递归中序
    if(p == NULL) return;
    bianLi1(p->lch);
    printf("%d ", p->val);
    bianLi1(p->rch);

}


void bianLi2(node* root){
    // 非递归中序
    node* q = root;
    node* A[MAX_N];int sz = 0;
    for(;q != NULL;q = q->lch){
        A[sz++] = q;
    }
    while((sz != 0)){
        q = A[--sz];
        printf("%d ",q->val);
        q = q->rch;
        for(;q!= NULL;q = q->lch){
            A[sz++] = q;
        }
    }
}
void bianLi3(node* root){
    //非递归前序
    node* A[MAX_N];int sz = 0;
    node* q = root;
    for(;q != NULL;q = q->lch){
        printf("%d ", q->val);
        A[sz++] = q->rch;
    }
    while(sz != 0){
        q = A[--sz];
        for(;q != NULL;q = q->lch){
            printf("%d ", q->val);
            A[sz++] = q->rch;
        }
    }
}
void bianLi4(node* root){
    //非递归后序
    // node* A[MAX_N];int sz = 0;
    // node* q = root;
    // while(q != NULL){
    //     A[sz++] = q;
    //     if(q->rch == NULL){
    //         break;
    //     }
    //     q = q->rch;
    // }
    // while(sz != 0){
    //     q = A[--sz];

    // }
}
node *root;
int main(){
    root = insert(root,5);
    insert(root,2);
    insert(root,3);
    insert(root,7);
    insert(root,9);
    insert(root,8);
    bianLi4(root);
    printf("\n");

}
