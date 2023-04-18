#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool usd[100005];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;++i){
		if(!usd[i]){
			usd[i]=true;
			++cnt;
			int now=i;
			while(!usd[a[now]]){
				usd[a[now]]=true;
				now=a[now];
			}
		}
	}
	int ans=n-cnt;
	if(ans>=k)cout<<ans-k<<" ";
	else cout<<(k-ans)%2<<" ";
	if(n-1-ans>=k)cout<<ans+k<<" ";
	else cout<<n-1-(k-(n-1-ans))%2<<" ";
	return 0;
}