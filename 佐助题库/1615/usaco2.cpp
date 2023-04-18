#include<bits/stdc++.h>
using namespace std;
struct ox{
	int x,y,id,ans;
	bool to,usd;
}a[55];
bool cmp(ox p,ox q){
	if(p.to!=q.to)return p.to<q.to;
	if(!p.to)return p.y<q.y;
	return p.x<q.x;
}
bool cmpp(ox p,ox q){
	return p.id<q.id;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		char t;
		cin>>t;
		if(t=='N')a[i].to=true;
		else a[i].to=false;
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	int pos;
	for(int i=1;i<=n;++i){
		if(a[i].to){
			pos=i;
			break;
		}
	}
	for(int i=1;i<pos;++i){
		bool ky=true;
		for(int j=pos;j<=n;++j){
			if(a[j].usd)break;
			if(a[i].y>=a[j].y&&a[i].x<=a[j].x&&a[j].x-a[i].x>a[i].y-a[j].y){
				a[i].ans=a[j].x-a[i].x;
				ky=false;
				break;
			}
			if(a[i].y>=a[j].y&&a[i].x<=a[j].x&&a[j].x-a[i].x<a[i].y-a[j].y){
				a[j].ans=a[i].y-a[j].y;
				a[j].usd=true;
			}
		}
		if(ky)a[i].ans=2147483647;
	}
	for(int i=pos;i<=n;++i)if(!a[i].usd)a[i].ans=2147483647;
	sort(a+1,a+1+n,cmpp);
	for(int i=1;i<=n;++i){
		if(a[i].ans==2147483647)printf("Infinity\n");
		else printf("%d\n",a[i].ans);
	}
	return 0;
}
