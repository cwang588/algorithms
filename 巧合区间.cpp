#include<bits/stdc++.h>
using namespace std;
map<long long,long long>num;
long long a[200005],b[200005];
int main(){
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long tot=0,ans=0;
	for(int i=1;i<=n;++i){
		tot+=a[i];
		b[i]=((tot-i)%k+k)%k;
	}
	int now=0;
	num[0]=1;
	for(int i=1;i<=n;++i){
		while(i-now>=k)--num[b[now++]];
		ans+=num[b[i]];
		++num[b[i]];
	}
	cout<<ans<<"\n";
	return 0;
}