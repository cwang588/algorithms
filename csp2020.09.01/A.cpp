#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y,id,dis;
}p[205];
bool cmp(point a,point b){
	if(a.dis!=b.dis)return a.dis<b.dis;
	return a.id<b.id;
}
int main(){
	int n,X,Y;
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
		p[i].dis=(X-p[i].x)*(X-p[i].x)+(Y-p[i].y)*(Y-p[i].y);
	}
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=3;++i)printf("%d\n",p[i].id);
	return 0;
}
