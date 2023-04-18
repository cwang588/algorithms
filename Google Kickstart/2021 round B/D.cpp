#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,nxt,l;
	long long a;
}e[400005];
int Head[200005],cnt;
void add(int x,int y,int l,long long a){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	e[cnt].l=l;
	e[cnt].a=a;
	Head[x]=cnt;
}
int root[200005],nodecnt;
struct node{
	int l,r;
	long long g;
	void init(){
		l=r=0;
		g=0;
	}
}T[200005*40];
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
void update(int rt){
	T[rt].g=gcd(T[T[rt].l].g,T[T[rt].r].g);
}
void build(int x,int &y,int l,int r,int pos,long long val){
	y=++nodecnt;
	T[y]=T[x];
	if(l==r){
		T[y].g=val;
		return;
	}
	int m=(l+r)>>1;
	if(pos<=m)build(T[x].l,T[y].l,l,m,pos,val);
	else build(T[x].r,T[y].r,m+1,r,pos,val);
	update(y);
}
long long query(int l,int r,int rt,int nowl,int nowr){
	if(nowl<=l&&r<=nowr)return T[rt].g;
	int m=(l+r)>>1;
	long long re=0;
	if(nowl<=m)re=gcd(re,query(l,m,T[rt].l,nowl,nowr));
	if(nowr>m)re=gcd(re,query(m+1,r,T[rt].r,nowl,nowr));
	return re;
}
void dfs(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		build(root[now],root[to],1,200000,e[i].l,e[i].a);
		dfs(to,now);
	}
}
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,q;
		cin>>n>>q;
		cnt=nodecnt=0;
		for(int i=1;i<=n;++i)Head[i]=0;
		for(int i=1;i<n;++i){
			int x,y,l;
			long long a;
			cin>>x>>y>>l>>a;
			add(x,y,l,a);
			add(y,x,l,a);
		}
		dfs(1,0);
		vector<long long>ans;
		for(int i=1;i<=q;++i){
			int c,w;
			cin>>c>>w;
			ans.push_back(query(1,200000,root[c],1,w));
		}
		cout<<"Case #"<<Case<<": ";
		for(auto x:ans)cout<<x<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}