#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
struct edge{
	int from,to,nxt;
}e[600006];
int Head[300005],cnt,u[300005],v[300005],n,m,k;
int a[300005],b[300005];
void add(int x,int y){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
int fa[300005][25],depth[300005];
void dfs(int now,int pre){
	fa[now][0]=pre;
	depth[now]=depth[pre]+1;
	for(int i=1;i<=20;++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfs(to,now);
	}
}
int lca(int x,int y){
	if(depth[x]<depth[y])swap(x,y);
	for(int i=20;i>=0;--i){
		if(depth[fa[x][i]]>=depth[y])x=fa[x][i];
	}
	if(x==y)return x;
	for(int i=20;i>=0;--i){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
long long ans;
long long fac[300005],inv[300005];
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%mod;
		now=now*now%mod;
		b>>=1;
	}
	return re;
}
void init(){
	fac[0]=1;
	for(int i=1;i<=300000;++i)fac[i]=fac[i-1]*i%mod;
	inv[300000]=quickpower(fac[300000],mod-2,mod);
	for(int i=300000;i>=1;--i)inv[i-1]=inv[i]*i%mod;
}
long long C(int x,int y){
	if(x<y)return 0;
	long long tmp=fac[x];
	tmp=tmp*inv[y]%mod;
	tmp=tmp*inv[x-y]%mod;
	return tmp;
}
void dfss(int now,int pre){
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre)continue;
		dfss(to,now);
		a[now]+=a[to];
	}	
	ans+=C(a[now],k)-C(a[now]-b[now],k);
	ans%=mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	init();
	while(t--){
		cin>>n>>m>>k;
		cnt=0;
		ans=0;
		a[0]=0;
		for(int i=1;i<=n;++i)Head[i]=a[i]=b[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			cin>>x>>y;
			add(x,y);
			add(y,x);
		}
		for(int i=1;i<=m;++i)cin>>u[i]>>v[i];
		dfs(1,0);
		for(int i=1;i<=m;++i){
			if(depth[u[i]]>depth[v[i]])swap(u[i],v[i]);
			int Lca=lca(u[i],v[i]);
			++a[u[i]],++a[v[i]];
			--a[Lca],--a[fa[Lca][0]];
			++b[Lca];
		}
		dfss(1,0);
		cout<<(ans%mod+mod)%mod<<"\n";
	}
	return 0;
}