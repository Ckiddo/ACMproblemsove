#include <stdio.h>
#include <cmath>

/*
0 0
10 0
0 0 1000
5 0 2
*/


int xc,yc;
int xd,yd;
int xb,yb,rb;
int xr,yr,rr;
long double _dis;
long double pi = 3.1415926535897932384626433832795;

void getin(){
	scanf("%d %d",&xc,&yc);
	scanf("%d %d",&xd,&yd);
	scanf("%d %d %d",&xb,&yb,&rb);
	scanf("%d %d %d",&xr,&yr,&rr);
}

long double distanceP_P(int x1,int y1,int x2,int y2){
	int d1 = x2 - x1;
	int d2 = y2 - y1;
	return sqrt(d1*d1 + d2*d2);
}
long double distanceP_L(int x,int y,int x1,int y1,int x2,int y2){
	int v1x = x - x1;
	int v1y = y - y1;
	int v2x = x2 - x1;
	int v2y = y2 - y1;
	int v3x = x2 - x;
	int v3y = y2 - y;
	long double disv1 = distanceP_P(x,y,x1,y1);
	long double disv2 = distanceP_P(x1,y1,x2,y2);
	long double disv3 = distanceP_P(x2,y2,x,y);
	//printf("disv1:%Lf disv2:%Lf disv3:%Lf\n", disv1,disv2,disv3);
	long double theta1 = acos(((v1x*v2x)+(v1y*v2y))/(disv1 * disv2));
	//printf("theta1:%Lf\n", theta1);
	long double theta2 = acos(((v2x*v3x)+(v2y*v3y))/(disv3 * disv2));
	//printf("theta2:%Lf\n", theta2);
	if(theta1 > pi/2){
		return disv1;
	}else if(theta2 > pi/2){
		return disv2;
	}else{
		return sin(theta1 * disv1);
	}
}

void compute(){
	long double d5 = distanceP_P(xc,yc,xd,yd);
	if(distanceP_L(xr,yr,xc,yc,xd,yd) >= rr){
		_dis = d5;
		return;
	}else{
		long double d3 = distanceP_P(xc,yc,xr,yr);
		long double d4 = distanceP_P(xr,yr,xd,yd);
		long double d1 = sqrt(d3*d3-rr*rr);
		long double d2 = sqrt(d4*d4 - rr*rr);
		long double theta1 = acos(rr/d3);
		long double theta2 = acos(rr/d4);
		int vecd3x = xc-xr;
		int vecd3y = yc-yr;
		int vecd4x = xd-xr;
		int vecd4y = yd-yr;
		long double theta3 = acos(((vecd3x*vecd4x)+(vecd3y*vecd4y))/(d3*d4));
		long double d6 = (theta3 - (theta2 + theta1) ) * rr;
		_dis = d1+d2+d6;
	}
}
void output(){
	printf("%.10Lf\n", _dis);
}

void solve(){
	getin();
	compute();
	output();
}

int main(){
	//printf("%Lf\n", distanceP_L(1,1,0,0,2,0));
	solve();

}