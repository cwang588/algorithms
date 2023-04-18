#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long p[30];
int l[1000005],r[1000005],fa[1000005];
vector<int>pos[10000005];
int prime[10000005],min_prime[10000005],p_cnt;
void xxs(int n){
	for(int i=2;i<=n;++i){
		if(!min_prime[i])prime[++p_cnt]=i;
		for(int j=1;j<=p_cnt&&i*prime[j]<=n;++j){
			min_prime[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}
bool divide(int L,int R,int Fa){
	if(L==R){
		fa[L]=Fa;
		return true;
	}
	if(L>=R)return true;
	for(int i=1;L+i-1<=R-i+1;++i){
		if(l[L+i-1]<L&&r[L+i-1]>R){
			fa[L+i-1]=Fa;
			return divide(L,L+i-2,L+i-1)&divide(L+i,R,L+i-1);
		}
		if(l[R-i+1]<L&&r[R-i+1]>R){
			fa[R-i+1]=Fa;
			return divide(L,R-i,R-i+1)&divide(R-i+2,R,R-i+1);
		}
	}
	cout<<"impossible\n";
	exit(0);
}
int main(){
	int n;
	scanf("%d",&n);
	xxs(10000000);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	int cnt=0;
	for(int i=1;i<=n;++i){
		r[i]=n+1;
		while(min_prime[a[i]]){
			int p=min_prime[a[i]];
			pos[p].push_back(i);
			while(a[i]%p==0)a[i]/=p;
		}
		if(a[i]>1)pos[a[i]].push_back(i);
	}
	for(int x=1;x<=10000000;++x){
		int len=pos[x].size();
		if(len<=1)continue;
		if(r[pos[x][0]]>pos[x][1])r[pos[x][0]]=pos[x][1];
		for(int i=1;i<len-1;++i){
			if(l[pos[x][i]]<pos[x][i-1])l[pos[x][i]]=pos[x][i-1];
			if(r[pos[x][i]]>pos[x][i+1])r[pos[x][i]]=pos[x][i+1];
		}
		if(l[pos[x][len-1]]<pos[x][len-2])l[pos[x][len-1]]=pos[x][len-2];
	}
	if(!divide(1,n,0))printf("impossible\n");
	else{
		for(int i=1;i<n;++i)printf("%d ",fa[i]);
		printf("%d ",fa[n]);
	}
	return 0;
}
