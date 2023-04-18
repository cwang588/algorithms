#include<bits/stdc++.h>
using namespace std;
const int INF=1000000000;
struct query{
	int l,r,lw,rw,id,ans,lca,lo,ro;
}q[300005];
priority_queue<int,vector<int>,greater<int> >s;
bool cmp(query x,query y){
	if(x.lw!=y.lw)return x.lw<y.lw;
	if(x.lw&1)return x.r<y.r;
	return x.r>y.r;
}
bool cmpp(query x,query y){
	return x.id<y.id;
}
int a[300005],num,st[100005],ed[100005],v[100005];
struct edge{
	int from,to,nxt,value;
}e[200005];
int Head[100005],cnt,fa[100005][25],depth[100005];
int sum[100005],summ[100005];
int usdcnt[100005];
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
void dfs(int now,int pre){
	depth[now]=depth[pre]+1;
	fa[now][0]=pre;
	for(int i=1;i<=19;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		v[to]=e[i].value;
		a[++num]=to;
		st[to]=num;
		dfs(to,now);
		a[++num]=to;
		ed[to]=num;	
	}
} 
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=19;i>=0;--i){
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=19;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
//set<int>s;
int main(){
	int n,m,base,basee;
	scanf("%d%d",&n,&m);
	base=sqrt(n*2);
	basee=sqrt(n);
	for(int i=1;i<n;++i){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	v[0]=v[1]=n+1;
	dfs(1,0);
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		q[i].lo=l;
		q[i].ro=r;
		if(st[l]>st[r])swap(l,r);
		int nowlca=lca(l,r);
		if(nowlca==l){
			q[i].l=st[l]+1;
			q[i].r=st[r];
		}
		else{
			q[i].l=ed[l];
			q[i].r=st[r];
		}
		q[i].lca=nowlca; 
		q[i].lw=(q[i].l-1)/base+1;
		q[i].rw=(q[i].r-1)/base+1;
		q[i].id=i;
	}
	sort(q+1,q+1+m,cmp);
	int l=0,r=0,tmpans=0;
	for(int i=1;i<=m;++i){
		while(r<q[i].r){
			++r;
			if(v[a[r]]>=n)continue;
			summ[a[r]]=(summ[a[r]]+1)%2;
			if(!summ[a[r]]){
				--sum[v[a[r]]];
				if(!sum[v[a[r]]])--usdcnt[v[a[r]]/basee];
			}
			else{
				++sum[v[a[r]]];
				if(sum[v[a[r]]]==1)++usdcnt[v[a[r]]/basee];
			}
		}
		while(l>q[i].l){
			--l; 
			if(v[a[l]]>=n)continue;
			summ[a[l]]=(summ[a[l]]+1)%2;
			if(!summ[a[l]]){
				--sum[v[a[l]]];
				if(!sum[v[a[l]]])--usdcnt[v[a[l]]/basee];
			}
			else{
				++sum[v[a[l]]];
				if(sum[v[a[l]]]==1)++usdcnt[v[a[l]]/basee];
			}
		}
		while(r>q[i].r){
			if(v[a[r]]>=n)goto next1;
			summ[a[r]]=(summ[a[r]]+1)%2;
			if(!summ[a[r]]){
				--sum[v[a[r]]];
				if(!sum[v[a[r]]])--usdcnt[v[a[r]]/basee];
			}
			else{
				++sum[v[a[r]]];
				if(sum[v[a[r]]]==1)++usdcnt[v[a[r]]/basee];
			}
			next1:--r;
		}
		while(l<q[i].l){
			if(v[a[l]]>=n)goto next2;
			summ[a[l]]=(summ[a[l]]+1)%2;
			if(!summ[a[l]]){
				--sum[v[a[l]]];
				if(!sum[v[a[l]]])--usdcnt[v[a[l]]/basee];
			}
			else{
				++sum[v[a[l]]];
				if(sum[v[a[l]]]==1)++usdcnt[v[a[l]]/basee];
			}
			next2:++l;
		}
		for(int j=0;j<=n/basee;++j){
			if(usdcnt[j]<basee){
				int nowstart=basee*j;
				for(int k=0;k<basee;++k){
					if(!sum[k+nowstart]){
						q[i].ans=k+nowstart;
						break;
					}
				}
				break;
			}
		}
	}
	sort(q+1,q+1+m,cmpp);
	for(int i=1;i<=m;++i)cout<<q[i].ans<<endl;
	return 0;
}
