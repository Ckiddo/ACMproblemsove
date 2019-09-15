#include <stdio.h>
#include <algorithm>

int n,k;
int a[500002];
int maxa[500002];
int mina[500002];
int _range[22][2];
int _rangeLength;
void solve();
void input(){
	while(scanf("%d %d",&n, &k) != -1){
		for(int i = 0;i < n;i++){
			scanf("%d", &a[i]);
		}
		std::fill(maxa,maxa+n,-1);
		std::fill(mina,mina+n,1000000001);
		solve();
	}	
	
}

void updateMin(int i){
	int left = 0;
	int range = n;
	int pos = i;
	int posFather;
	int upbound = 2 * n + 1;
	int sonNum = a[i/2*2];
	int sonNum2;
	if(i/2*2 + 1 < n){
		sonNum2 = a[i/2*2 + 1];
	}else{
		sonNum2 = 1000000001;
	}
	while(range > 1){
		// printf("min:%d %d %d\n", pos, sonNum, sonNum2);
		posFather = (pos - left) / 2 + left + range;
		mina[posFather - n] = std::min(sonNum, sonNum2);
		pos = posFather;
		left = left + range;
		if(range == 1){
			range = 0;
		}
		range = (range + 1) / 2;


		sonNum = mina[(pos - left) / 2 * 2 + left - n];
		if((pos - left) / 2 * 2 + 1 + left < left + range){
			sonNum2 = mina[(pos - left) / 2 * 2 + 1 + left - n];
		}else{
			sonNum2 = 1000000001;
		}
	
		
		
		
	}
}

void updateMax(int i){
	int left = 0;
	int range = n;
	int pos = i;
	int posFather;
	int upbound = 2 * n + 1;
	int sonNum = a[i/2*2];
	int sonNum2;
	if(i/2*2 + 1 < n){
		sonNum2 = a[i/2*2 + 1];
	}else{
		sonNum2 = -1;
	}
	while(range > 1){
		// printf("max:%d %d %d\n", pos, sonNum, sonNum2);
		posFather = (pos - left) / 2 + left + range;
		maxa[posFather - n] = std::max(sonNum, sonNum2);
		pos = posFather;
		left = left + range;
		if(range == 1){
			range = 0;
		}
		range = (range + 1) / 2;


		sonNum = maxa[(pos - left) / 2 * 2 + left - n];
		if((pos - left) / 2 * 2 + 1 + left < left + range){
			sonNum2 = maxa[(pos - left) / 2 * 2 + 1 + left - n];
		}else{
			sonNum2 = -1;
		}
	}
}

void showmin(){
	printf("min:\n");
	for(int i = 0;i < n;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	int left = n;
	int range = (n+1)/2;
	int upbound = 2 * n + 1;

	while(range > 0){
		
		for(int i = 0;i < range;i++){
			printf("%d\t", mina[left + i - n]);
		}
		printf("\n");

		left = left + range;
		if(range == 1){
			range = 0;
		}
		range = (range + 1) / 2;
	}
}

void showmax(){
	printf("max:\n");
	for(int i = 0;i < n;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	int left = n;
	int range = (n+1)/2;
	int upbound = 2 * n + 1;

	while(range > 0){
		
		for(int i = 0;i < range;i++){
			printf("%d\t", maxa[left + i - n]);
		}
		printf("\n");
		
		left = left + range;
		if(range == 1){
			range = 0;
		}
		range = (range + 1) / 2;
		
	}

}
void recordRange(){
	int left = 0;
	int range = n;
	int upbound = 2 * n + 1;
	_rangeLength = 0;
	while(range > 0){
		
		_range[_rangeLength][0] = left;
		_range[_rangeLength][1] = range;
		_rangeLength++;
		left = left + range;
		if(range == 1){
			range = 0;
		}
		range = (range + 1) / 2;
	}
}

int findMinPos(){
	int posFather = _range[_rangeLength-1][0];
	int leftSon, rightSon;
	int minner;
	int i;
	for(i = _rangeLength-1;i >= 2;i--){
		leftSon = (posFather - _range[i][0]) * 2 + _range[i-1][0];
		minner = leftSon;
		rightSon = (posFather - _range[i][0]) * 2 + 1 + _range[i-1][0];
		if(rightSon < _range[i-1][0] + _range[i-1][1] && mina[rightSon - n] < mina[leftSon - n]){
			minner = rightSon;
		}

		posFather = minner;

	}
	leftSon = (posFather - _range[i][0]) * 2 + _range[i-1][0];
	minner = leftSon;
	rightSon = (posFather - _range[i][0]) * 2 + 1 + _range[i-1][0];
	if(rightSon < _range[i-1][0] + _range[i-1][1] && a[rightSon] < a[leftSon]){
		minner = rightSon;
	}
	return minner;
}
int findMaxPos(){
	int posFather = _range[_rangeLength-1][0];
	int leftSon, rightSon;
	int maxer;
	int i;
	for(i = _rangeLength-1;i >= 2;i--){
		leftSon = (posFather - _range[i][0]) * 2 + _range[i-1][0];
		maxer = leftSon;
		rightSon = (posFather - _range[i][0]) * 2 + 1 + _range[i-1][0];
		if(rightSon < _range[i-1][0] + _range[i-1][1] && maxa[rightSon - n] > maxa[leftSon - n]){
			maxer = rightSon;
		}

		posFather = maxer;

	}
	leftSon = (posFather - _range[i][0]) * 2 + _range[i-1][0];
	maxer = leftSon;
	rightSon = (posFather - _range[i][0]) * 2 + 1 + _range[i-1][0];
	if(rightSon < _range[i-1][0] + _range[i-1][1] && a[rightSon] > a[leftSon]){
		maxer = rightSon;
	}
	return maxer;
}
void showa(){
	printf("a:\n");
	for(int i = 0;i < n;i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void solve(){
	for(int i = 0;i < n;i++){
		updateMin(i);
		updateMax(i);
	}

	int pos;
	recordRange();
	for(int i = 0;i < k;i++){
		pos = findMaxPos();
		// printf("maxpos: %d\n", pos);
		a[pos]--;
		updateMax(pos);
		updateMin(pos);
		pos = findMinPos();
		// printf("minpos: %d\n", pos);
		a[pos]++;
		updateMax(pos);
		updateMin(pos);
		// showmin();
		// showmax();
	}
	// showmin();
	// showmax();
	printf("%d\n", maxa[_range[_rangeLength-1][0] - n] - mina[_range[_rangeLength-1][0] - n]);
}

int main(){

	input();
	// solve();
}