#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y;
	long long value;
}e[200005];
int fa[100005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}//Â·¾¶Ñ¹Ëõ 
void Merge(int x,int y){
	fa[x]=y;
}
bool cmp(edge a,edge b){
	return a.value<b.value;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%lld",&e[i].x,&e[i].y,&e[i].value);
	sort(e+1,e+1+m,cmp);
	int cnt=0;
	long long tot=0;
	for(int i=1;i<=m;++i){
		int x=e[i].x,y=e[i].y;
		int r1=getfa(x),r2=getfa(y);
		if(r1!=r2){
			tot+=e[i].value;
			Merge(r1,r2);
			++cnt;
		}
		if(cnt==n-1)break;
	}
	if(cnt<n-1)printf("orz\n");
	else printf("%lld\n",tot);
	return 0;
}
