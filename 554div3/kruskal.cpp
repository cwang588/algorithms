#include<bits/stdc++.h>
using namespace std;
int fa[5005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
struct edge{
	int x,y,z;
}e[200005];
bool cmp(edge a,edge b){
	return a.z<b.z;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=m;++i){
		int r1=getfa(e[i].x),r2=getfa(e[i].y);
		if(r1!=r2){
			ans+=e[i].z;
			Merge(r1,r2);
			++cnt;
		}
		if(cnt==n-1)break;
	}
	printf("%lld\n",ans);
	return 0;
}
