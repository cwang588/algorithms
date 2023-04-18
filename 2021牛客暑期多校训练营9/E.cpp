#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt;
}e[2000005];
int cnt,tot,Head[1000005],t[1000005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
struct query{
	int l,r,x;
}q[1000005];
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
struct node{
	int l,r,sum;
}T[1000005*40];
int root[1000005],id[1000005],idnum,nodecnt,sz[1000005];
void modify(int l,int r,int &x,int y,int k){
	T[++nodecnt]=T[y];
	x=nodecnt;
	++T[x].sum;
	if(l==r)return;
	int m=(l+r)>>1;
	if(k<=m)modify(l,m,T[x].l,T[y].l,k);
	else modify(m+1,r,T[x].r,T[y].r,k);
}
int query(int l,int r,int x,int y,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return T[y].sum-T[x].sum;
	int m=(l+r)>>1;
	int re=0;
	if(nowl<=m)re+=query(l,m,T[x].l,T[y].l,nowl,nowr);
	if(nowr>m)re+=query(m+1,r,T[x].r,T[y].r,nowl,nowr);
	return re;
}
int fa[100005][25];
void dfs(int now,int pre){
	fa[now][0]=pre;
	for(int i=1;i<=20;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	sz[now]=1;
	id[now]=++idnum;
	modify(1,tot,root[idnum],root[idnum-1],getid(t[now]));
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
void build(int l,int r,int &rt){
	rt=++nodecnt;
	T[rt].sum=0;
	if(l==r)return;
	int m=(l+r)>>1;
	build(l,m,T[rt].l);
	build(m+1,r,T[rt].r);
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,m;
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;++i)cin>>t[i],v.push_back(t[i]);
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>q[i].x>>q[i].l>>q[i].r;
		v.push_back(q[i].l);
		v.push_back(q[i].r);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	tot=v.size();
	build(1,tot,root[0]);
	dfs(1,0);
	t[0]=2147483647;
	for(int i=1;i<=m;++i){
		int now=q[i].x;
		if(t[now]<q[i].l||t[now]>q[i].r){
			cout<<"0\n";
			continue;
		}
		for(int j=20;j>=0;--j){
			if(t[fa[now][j]]<=q[i].r)now=fa[now][j];
		}
		cout<<query(1,tot,root[id[now]-1],root[id[now]+sz[now]-1],getid(q[i].l),getid(q[i].r))<<endl;
	}
	return 0;
}
