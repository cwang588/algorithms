#include<bits/stdc++.h>
using namespace std;
int value[600005],fa[600005],limit[600005];
struct Edge{
	int x,y,z;
}E[500005];
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
int num;
struct edge{
	int from,to,nxt;
}e[1000005];
int Head[600005],cnt;
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int f[600005][25],dfn[600005],sz[600005],dfnpos[600005],dfncnt;
void dfs(int now,int pre){
	dfn[++dfncnt]=now;
	dfnpos[now]=dfncnt;
	sz[now]=1;
	f[now][0]=pre;
	for(int i=1;i<=20;++i)f[now][i]=f[f[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
		sz[now]+=sz[to];
	}
}
vector<int>v;
int getid(int x){
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int root[500005],nodecnt;
struct Node{
	int l,r,value;
}T[500005*40];
int update(int l,int r,int node,int pos){
	T[++nodecnt]=T[node];
	node=nodecnt;
	if(l==r){
		++T[node].value;
		return node;
	}
	int mid=(l+r)>>1;
	if(pos<=mid)T[node].l=update(l,mid,T[node].l,pos);
	else T[node].r=update(mid+1,r,T[node].r,pos);
	T[node].value=T[T[node].l].value+T[T[node].r].value;
	return node;
}
int query(int l,int r,int x,int y,int k){
	if(l==r)return l;
	int mid=(l+r)>>1,sum=T[T[y].l].value-T[T[x].l].value;
	if(sum>=k)return query(l,mid,T[x].l,T[y].l,k);
	else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",&value[i]),v.push_back(value[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=3*n;++i)fa[i]=i;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].z);
	sort(E+1,E+1+m,cmp);
	num=n;
	for(int i=1;i<=m;++i){
		int r1=getfa(E[i].x),r2=getfa(E[i].y);
		if(r1!=r2){
			++num;
			fa[r1]=fa[r2]=num;
			add(num,r1);		
			add(r1,num);		
			add(num,r2);
			add(r2,num);		
			limit[num]=E[i].z;
		}
	}
	++num;
	for(int i=1;i<num;++i){
		if(fa[i]==i){
			fa[i]=num;
			add(num,i);
			add(i,num);
		}
	}
	dfs(num,0);
	limit[num]=2147483647;
	for(int i=1;i<=num;++i){
		if(value[dfn[i]])root[i]=update(1,n,root[i-1],getid(value[dfn[i]]));
		else root[i]=root[i-1];
	}
	while(q--){
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		int tmp=x;
		for(int i=20;i>=0;--i)if(f[tmp][i]&&limit[f[tmp][i]]<=y)tmp=f[tmp][i];
		int sum=T[root[dfnpos[tmp]+sz[tmp]-1]].value-T[root[dfnpos[tmp]-1]].value;
		if(sum<k)printf("-1\n");
		else printf("%d\n",v[query(1,n,root[dfnpos[tmp]-1],root[dfnpos[tmp]+sz[tmp]-1],sum-k+1)-1]);
	}
	return 0;
}
