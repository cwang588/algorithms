#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
}p[1005];
int fa[1005];
void Merge(int x,int y){
	fa[x]=y;
}
int getfa(int x){
	if(x!=fa[x])fa[x]=getfa(fa[x]);
	return fa[x];
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d%d",&p[i].x,&p[i].y),fa[i]=i;
	for(int i=1;i<=m;++i){
		for(int j=i+1;j<=m;++j){
			if(p[i].x==p[j].x||p[i].y==p[j].y){
				int r1=getfa(i),r2=getfa(j);
				if(r1!=r2)Merge(r1,r2);
			}
		}
	}
	int ans=m;
	for(int i=1;i<=m;++i)if(fa[i]==i)--ans;
	printf("%d\n",ans);
	return 0;
}
