#include<bits/stdc++.h>
using namespace std;
int fa[100005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			int r1=getfa(x),r2=getfa(y);
			if(r1!=r2)Merge(r1,r2);
		}
		else{
			int r1=getfa(x),r2=getfa(y);
			if(r1==r2)printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
