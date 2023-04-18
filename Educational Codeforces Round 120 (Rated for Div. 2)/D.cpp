#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
vector<int>pos;
long long C[5005][5005];
void init(){
	for(int i=0;i<=5000;++i)C[i][0]=1;
	for(int i=1;i<=5000;++i){
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
}
int main(){
	init();
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=0;i<n;++i)if(s[i]=='1')pos.push_back(i);
	if(k==0||k>pos.size())return !printf("1\n");
	if(k==pos.size())return !printf("%I64d\n",C[n][k]);
	long long ans=C[pos[k]][k];
	pos.push_back(n);
	for(int i=1;i+k<pos.size();++i){
		ans+=C[pos[i+k]-pos[i-1]-1][k]-C[pos[i+k-1]-pos[i-1]-1][k-1];
		ans%=mod;
	}
	ans=(ans+mod)%mod;
	cout<<ans<<"\n";
	return 0;
}