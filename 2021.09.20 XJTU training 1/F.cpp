#include<bits/stdc++.h>
using namespace std;
int x[100005],y[100005],tx[100005],ty[100006];
long long getid(int x,int y){
	return 1000000002ll*x+y;
}
unordered_map<long long,int>m;
long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
bool usd[100005];
int main(){
	int n,p;
	cin>>n>>p;
	int k=(n*p-1)/100+1;
	srand((unsigned)time(0));
	for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
	for(int i=1;i<=min(n,100);++i){
		m.clear();
		int now=rand()*rand()%n+1;
		while(usd[now])now=rand()*rand()%n+1;
		usd[now]=true;
		for(int j=1;j<=n;++j)tx[j]=x[j]-x[now],ty[j]=y[j]-y[now];
		int tmp=0;
		for(int j=1;j<=n;++j){
			long long g=gcd(abs(tx[j]),abs(ty[j]));
			if(!g)continue;
			tx[j]/=g,ty[j]/=g;
			if(ty[j]<0)tx[j]=-tx[j],ty[j]=-ty[j];
			else if(ty[j]==0){
				tx[j]=abs(tx[j]);
			}
			else;
			long long noww=getid(tx[j],ty[j]);
			++m[noww];
			tmp=max(tmp,m[noww]);
		}
		if(tmp+1>=k)return !printf("possible\n");
	}
	printf("impossible\n");
	return 0;
}
