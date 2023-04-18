#include<bits/stdc++.h>
using namespace std;
struct edge{
	int from,to,value,nxt;
}e[200005];
int Head[100005],cnt;
void add(int x,int y,int z){
	++cnt;
	e[cnt].from=x;
	e[cnt].to=y;
	e[cnt].value=z;
	e[cnt].nxt=Head[x];
	Head[x]=cnt;
}
bool usd[100005];
int rt,sum;
int sz[100005],maxp[100005];
void getrt(int now,int pre){
	sz[now]=1;
	maxp[now]=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		getrt(to,now);
		sz[now]+=sz[to];
		maxp[now]=max(maxp[now],sz[to]);
	}
	maxp[now]=max(maxp[now],sum-sz[now]);
	if(maxp[now]<maxp[rt])rt=now;
}
long long ans;
int num[3],nownum[3];
void getdis(int now,int pre,int tot){
	tot%=3;
	++nownum[tot];
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(to==pre||usd[to])continue;
		getdis(to,now,tot+e[i].value);
	}
}
void calc(int now){
    num[0]=num[1]=num[2]=0;
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to])continue;
		nownum[0]=nownum[1]=nownum[2]=0;
		getdis(to,now,e[i].value);
		for(int j=0;j<=2;++j)ans+=1ll*nownum[j]*num[(3-j)%3];
		ans+=nownum[0];
		for(int j=0;j<=2;++j)num[j]+=nownum[j];
	}
}
void solve(int now){
	usd[now]=true;
	calc(now);
	for(int i=Head[now];i;i=e[i].nxt){
		int to=e[i].to;
		if(usd[to])continue;
		sum=sz[to];
		maxp[rt=0]=2147483647;
		getrt(to,0);
		solve(rt);
	}
}
long long gcd(long long x,long long y){
	return y?gcd(y,x%y):x;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<n;++i){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}	
	sum=n;
	maxp[rt]=n;
	getrt(1,0);
	solve(rt);
	long long g=gcd(ans*2+n,1ll*n*n);
	cout<<(ans*2+n)/g<<"/"<<1ll*n*n/g<<"\n";
	return 0;
}