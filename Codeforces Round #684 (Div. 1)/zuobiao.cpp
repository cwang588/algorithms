#include<bits/stdc++.h>
using namespace std;
struct point{
	double x,y,z;
}p[105];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
void init(){
	p[0].x=1.0;
	p[0].y=11.0;
	p[0].z=1111.0;
	p[1].x=151.0;
	p[2].y=11.0;
	p[3].z=1354.0;
}
int main(){
	
	return 0;
}
