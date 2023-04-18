#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
set<int>s[1000005];
int a[1000005],d_num[1000005],t_num[1000005];
vector<int>pos[1000005];
void add(int pos,int num){
	if(s[pos].count(num))s[pos].erase(num);
	else s[pos].insert(num);
}
long long quickpower(long long a,long long b,long long p){
	long long re=1,now=a;
	while(b){
		if(b&1)re=re*now%p;
		now=now*now%p;
		b>>=1;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0); 
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		int tmp=a[i];
		for (int j=2;j*j<=tmp;++j)
		{
			if (tmp%j==0)
			{
				add(i, j);
				tmp/=j;
				--j;
			}
		}
		if (tmp>1)
			add(i,tmp);
	}
	long long ans=1;
	for(int i=1;i<=n;++i){
		for(auto x:s[i]){
			++t_num[x];
			pos[x].push_back(i);
			if(!s[i-1].count(x)&&!s[i+1].count(x))++d_num[x];	
		}
	}
	for(int i=1;i<=1000000;++i){
		if(!t_num[i])continue;
		int tmp=min(t_num[i],n-t_num[i]);
		ans=ans*quickpower(i,tmp,mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
