#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
}p[500005];
bool cmp(point a,point b){
	if(a.x!=b.x)return a.x>b.x;
	return a.y>b.y;
}
int ans[500005];
int main(){
	int n,num=0,maxy=-2147483648;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&p[i].x,&p[i].y);
	sort(p+1,p+1+n,cmp);
	for(int i=1;i<=n;++i){
		if(p[i].y>=maxy){
			ans[++num]=i;
			maxy=p[i].y;
		}
	}
	for(int i=num;i>=1;--i)printf("%d %d\n",p[ans[i]].x,p[ans[i]].y);
	return 0;
}
