#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,type;
	long long value;
}e[200005];
bool cmp(edge x,edge y){
	return x.value<y.value;
}
//struct graph{
//	edge e[200005];
//	int cnt,n,m,fa[100005];
//	int getfa(int x){
//		if(fa[x]!=x)fa[x]=getfa(fa[x]);
//		return fa[x];
//	}
//	void Merge(int x,int y){
//		fa[x]=y;
//	}
//	void add(int x,int y,long long z){
//		++cnt;
//		e[cnt].from=x;
//		e[cnt].to=y;
//		e[cnt].value=z;
//	}
//	long long getvalue(){
//		sort(e+1,e+1+cnt,cmp);
//		for(int i=1;i<=n;++i)fa[i]=i;
//		long long tot=0;
//		for(int i=1;i<=cnt;++i){
//			int x=e[i].from,y=e[i].to;
//			int r1=getfa(x),r2=getfa(y);
//			if(r1==r2)continue;
//			tot+=e[i].value;
//			Merge(r1,r2);
//		}
//		return tot;
//	}
//}a,b;
int fa[2][100005];
int getfa(int x,int op){
	if(fa[op][x]!=x)fa[op][x]=getfa(fa[op][x],op);
	return fa[op][x];
}
void Merge(int x,int y,int op){
	fa[op][x]=y;
}
int main(){
	ios::sync_with_stdio(false);
	int n,nn,m,mm;
	cin>>n>>m>>nn>>mm;
	for(int i=1;i<=n;++i)fa[0][i]=i;
	for(int i=1;i<=nn;++i)fa[1][i]=i;
	for(int i=1;i<=m;++i){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		++x,++y;
		e[i].from=x;
		e[i].to=y;
		e[i].value=z;
		e[i].type=1;
	}
	for(int i=1;i<=mm;++i){
		int x,y;
		long long z;
		cin>>x>>y>>z;
		++x,++y;
		e[i+m].from=x;
		e[i+m].to=y;
		e[i+m].value=z;
		e[i+m].type=2;
	}
	sort(e+1,e+1+m+mm,cmp);
	int r1=n,r2=nn;
	long long ans=0,num=n*nn-1;
	for(int i=1;i<=m+mm;++i){
		int x=e[i].from,y=e[i].to;
		if(e[i].type==1){
			int rr1=getfa(x,0),rr2=getfa(y,0);
			if(rr1==rr2)continue;
			Merge(rr1,rr2,0);
			ans+=e[i].value*r2;
			--r1;
		}
		else{
			int rr1=getfa(x,1),rr2=getfa(y,1);
			if(rr1==rr2)continue;
			Merge(rr1,rr2,1);
			ans+=e[i].value*r1;
			--r2;
		}
	}
	cout<<ans;
	return 0;
}
