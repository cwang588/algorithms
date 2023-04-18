#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y,id;
	bool type,attacked;
}p[400005];
bool cmp1(point a,point b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
bool cmp2(point a,point b){
	return a.y==b.y?a.x<b.x:a.y<b.y;
}
bool cmp3(point a,point b){
	return a.type==b.type?a.id<b.id:a.type<b.type;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>p[i].x>>p[i].y;
		p[i].id=i;
		p[i].type=false;
	}
	for(int i=1;i<=m;++i){
		cin>>p[i+n].x>>p[i+n].y;
		p[i+n].id=i;
		p[i+n].type=true;
	}
	sort(p+1,p+1+n+m,cmp1);
	for(int i=1;i<n+m;++i){
		if(p[i].x==p[i+1].x&&p[i].type!=p[i+1].type)p[i].attacked=p[i+1].attacked=true;
	}
	sort(p+1,p+1+n+m,cmp2);
	for(int i=1;i<n+m;++i){
		if(p[i].y==p[i+1].y&&p[i].type!=p[i+1].type)p[i].attacked=p[i+1].attacked=true;
	}
	sort(p+1,p+1+n+m,cmp3);
	for(int i=1;i<=n;++i)cout<<(p[i].attacked?1:0);
	cout<<endl;
	for(int i=1;i<=m;++i)cout<<(p[i+n].attacked?1:0);
	cout<<endl;
	return 0;
}
