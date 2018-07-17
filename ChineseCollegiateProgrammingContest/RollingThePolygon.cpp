#include <stdio.h>
#include <math.h>
#include <cmath>

int n;
int points[50][2];
int q[2];
double distances[50];
double angels[50];
double _distance;

void getin(){
	scanf("%d",&n);
	int x,y;
	for(int j = 0;j < n;j++){
		scanf("%d %d",&x,&y);
		points[j][0] = x;
		points[j][1] = y;
	}
	scanf("%d %d",&x,&y);
	q[0] = x;
	q[1] = y;
}
double distance(int x1,int y1,int x2,int y2){
	double x = (x2 - x1);
	double y = (y2 - y1);
	double sq =sqrt(x*x + y*y);
	return sq;
}
double angel(int x1,int y1,int x2,int y2,int x3,int y3){
	int v1x = x1 - x2;
	int v1y = y1 - y2;
	int v2x = x3 - x2;
	int v2y = y3 - y2;
	double v1d = distance(x1,y1,x2,y2);
	double v2d = distance(x2,y2,x3,y3);
	double cosA = (v1x * v2x + v1y * v2y)/(v1d * v2d);
	return acos(cosA);
}
void computeAngleR(){
	for(int i = 0;i < n;i++){
		distances[i] = distance(q[0],q[1],points[i][0],points[i][1]);
		int iq;
		int ih;
		iq = i - 1;
		if(iq < 0){
			iq += n;
		}
		ih = i+1;
		if(ih >=n){
			ih -=n;
		}
		angels[i] = 3.1415926535879932 - angel(points[iq][0],points[iq][1],points[i][0],points[i][1],points[ih][0],points[ih][1]);
		//printf("get:%lf %lf\n", distances[i],angels[i]);
	}
}
void computeAnswer(){
	double distan = 0;
	for(int i = 0;i < n;i++){
		distan += distances[i] * angels[i];
	}
	_distance = distan;
}
void output(int i){
	printf("Case #%d: %.3f\n", i+1,_distance);
}

void solve(int i){
	getin();
	computeAngleR();
	computeAnswer();
	output(i);
}


int main(){
	int T = 0;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		solve(i);
	}
}