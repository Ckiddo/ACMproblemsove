#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct information
{
	int a; // 原始数据
	int b; // 进了哪个轨道
};
class Vector{
public:
	int* data;
	int _size;
	int _capacity;
	Vector(){
		_capacity = 10;
		data = new int[_capacity];
		_size = 0;

	}
	int min(){
		if(_size == 0){return -1;}
		return data[0];
	}
	int max(){
		if(_size == 0){return -1;}
		return data[_size - 1];
	}
	int add(int e){
		if(_size == _capacity - 1){
			_capacity = _capacity * 2;
			// printf("扩容了\n");
			int* ndata = new int[_capacity];
			for(int i = 0;i < _size;i++){
				ndata[i] = data[i];
			}
			delete data;
			data = ndata;
		}
		data[_size] = e;
		_size++;
		return _size;
	}
};


//
int compare_ints(const void* a, const void* b)
{
	information* inf1;
	information* inf2;
	inf1 = (information*)a;
	inf2 = (information*)b;
    int arg1 = inf1->a;
    int arg2 = inf2->a;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}
//
int main(){
	int n = 0;
	int m = 0;

	while(scanf("%d %d",&n,&m) && (n != 0 && m != 0)){
		Vector store[m+1];
		// int line1[200000];int p =1; // 位置记录
		// int line2[200000];int in = 1; // 记录原输入数据
		information line[200000];int p = 1;
		bool tf = false;
		int t;
		scanf("%d",&t);
		store[0].add(t);
		// line1[0] = 1;
		// line2[0] = t;
		line[0].a = t;
		line[0].b = 1;

		int size_m = 1;
		for(int i = 1;i < n;i++){ // 输入
			scanf("%d",&t);
			if(tf){continue;}
			// add to store
				// t 应该放到第几列: lo
			int lo = 0;int hi = m + 1;int mi = (lo + hi)/2;
			while(hi - lo > 1){
				// compare store[mi].max() 和 t
				if(store[mi].max() > t){
					lo = mi+1;
					mi = (lo + hi)/2;
				}else{ // store[mi].max() <= t
					hi = mi + 1;
					mi = (lo + hi)/2;
				}
				if(hi - lo == 2){
					if(store[lo].max() <= t){break;}
					if(store[lo + 1].max() <= t){lo++;break;}
				}
			}

			if(lo >= m){
				tf = true;
			}else{
				store[lo].add(t);
				// line1[p] = lo + 1;
				// line2[p] = t;
				line[p].a = t;
				line[p].b = lo+1;
				p++;

			}
			
		}
		// 输出

		if(tf){printf("Transportation failed\n");}
		else{	
			for(int i = 0;i < p;i++){
				printf("%d ", line[i].b);
			}
			printf("\n");
			//
			// 对line进行排序:
			int size = (sizeof line / sizeof *line)*p/200000;
			qsort(line,size,sizeof(information),compare_ints);
			for(int i = 0;i < p;i++){
				printf("%d ", line[i].b);
			}
			printf("\n");
	
			//
		}
		


	}
}