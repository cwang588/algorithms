#include<bits/stdc++.h>
#define maxn 200006
using namespace std;
struct SuffixArray {
	int s[maxn];
	int n,m,lg2[maxn],st[maxn][35],y[maxn],x[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],wt[30];
	void init() {
		memset(c,0,sizeof(c));
		memset(y,0,sizeof(y));
		memset(x,0,sizeof(x));
	}
	void get_SA() {
		for(int i=1; i<=n; ++i)++c[x[i]=s[i]];
		for(int i=2; i<=m; ++i)c[i]+=c[i-1];
		for(int i=n; i>=1; --i)sa[c[x[i]]--]=i;
		for(int k=1; k<=n; k<<=1) {
			int num=0;
			for(int i=n-k+1; i<=n; ++i)y[++num]=i;
			for(int i=1; i<=n; ++i)if(sa[i]>k)y[++num]=sa[i]-k;
			for(int i=1; i<=m; ++i)c[i]=0;
			for(int i=1; i<=n; ++i)++c[x[i]];
			for(int i=2; i<=m; ++i)c[i]+=c[i-1];
			for(int i=n; i>=1; --i)sa[c[x[y[i]]]--]=y[i],y[i]=0;
			swap(x,y);
			x[sa[1]]=1;
			num=1;
			for(int i=2; i<=n; ++i)x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?num:++num;
			if(num==n)break;
			m=num;
		}
	}
	void get_height() {
		int k=0;
		for(int i=1; i<=n; ++i)rk[sa[i]]=i;
		for(int i=1; i<=n; ++i) {
			if(rk[i]==1)continue;
			if(k)--k;
			int j=sa[rk[i]-1];
			while(j+k<=n&&i+k<=n&&s[i+k]==s[j+k])++k;
			height[rk[i]]=k;
		}
	}
	void get_lcp() {
		lg2[0]=-1;
		for(int i=1; i<maxn; i++)lg2[i]=lg2[i/2]+1;
		lg2[0]=0;
		for(int i=1; i<=n; i++)st[i][0]=height[i];
		for(int j=1; (1<<j)<=n; j++)
			for(int i=1; i+(1<<j)-1<=n; i++)
				st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	}
	int Lcp(int l,int r) {
		l=rk[l],r=rk[r];
		if(l>r)swap(l,r);
		l++;
		int k=lg2[r-l+1];
		return min(st[l][k],st[r-(1 << k)+1][k]);
	}
} SA;
vector<int>v;
int getid(int x) {
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int a[200005];
struct edge {
	int from,to,nxt;
	long long value;
} e[2000006];
int Head[1000006],cnt,Next[1000006];
void add(int x,int y,long long z) {
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
stack<int>s;
int fa[maxn][25];
long long tot[maxn];
void dfs(int now,int pre) {
	fa[now][0]=pre;
	for(int i=1; i<=20; ++i)fa[now][i]=fa[fa[now][i-1]][i-1];
	for(int i=Head[now]; i; i=e[i].nxt) {
		int to=e[i].to;
		if(to==pre)continue;
		tot[to]=tot[now]+e[i].value;
		dfs(to,now);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		SA.n=n;
		cnt=0;
		for(int i=1; i<=n+1; ++i)Head[i]=0;
		v.clear();
		for(int i=1; i<=n; ++i)cin>>a[i],v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		SA.m=v.size();
		for(int i=1; i<=n; ++i)SA.s[i]=getid(a[i]);
		SA.init(),SA.get_SA(),SA.get_height(),SA.get_lcp();
		while(!s.empty())s.pop();
		a[n+1]=19260817;
		for(int i=1; i<=n+1; ++i) {
			while(!s.empty()&&a[s.top()]<a[i]) {
				int now=s.top();
				Next[now]=i;
				add(now,i,1ll*a[now]*(i-now));
				add(i,now,1ll*a[now]*(i-now));
				s.pop();
			}
			s.push(i);
		}
		tot[n+1]=0;
		dfs(n+1,n+1);
		long long ans=0;
	//	string bkx="fjcsb!";
		for(int i=1; i<=n; ++i) {
			int now=i,bound=i+SA.height[SA.rk[i]]-1;
			if(SA.height[SA.rk[i]]==0){
				ans+=tot[i];
				continue;
			}
			if(bound>=n)continue;
			for(int j=20; j>=0; --j)if(fa[now][j]<=bound)now=fa[now][j];
			ans+=1ll*a[now]*(fa[now][0]-bound-1)+tot[fa[now][0]];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
