#include<bits/stdc++.h>
using namespace std;
const unsigned long long mod=1000000007;
unsigned long long k1,k2;
unsigned long long xorShift128Plus(){
	unsigned long long k3=k1,k4=k2;
	k1=k4;
	k3^=k3<<23;
	k2=k3^k4^(k3>>17)^(k4>>26);
	return k2+k4;
}
int n,m;
struct edge{
	int u,v;
	unsigned long long w;
}e[1000005];
void gen(){
	cin>>n>>m>>k1>>k2;
	for(int i=1;i<=m;++i){
		e[i].u=xorShift128Plus()%n+1;
		e[i].v=xorShift128Plus()%n+1;
		e[i].w=xorShift128Plus();
	
	}
}
int fa[1000005];
int getfa(int x){
	if(fa[x]!=x)fa[x]=getfa(fa[x]);
	return fa[x];
}
void Merge(int x,int y){
	fa[x]=y;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		gen();
		for(int i=1;i<=n;++i)fa[i]=i;
		sort(e+1,e+1+m,cmp);
		unsigned long long ans=0;
		int cnt=0;
		for(int i=1;i<=m;++i){
			int r1=getfa(e[i].u),r2=getfa(e[i].v);
			if(r1!=r2){
				++cnt;
				ans+=e[i].w;
				ans%=mod;
				Merge(r1,r2);
			}
		}
		if(cnt!=n-1)cout<<"0\n";
		else cout<<ans<<"\n";
	}
	
	
	return 0;
}