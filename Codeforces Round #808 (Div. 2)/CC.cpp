#include<bits/stdc++.h>
using namespace std;
int a[100005],sum[100005],num[100005];
bool usd[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,q;
		cin>>n>>q;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			sum[i]=sum[i-1];
			usd[i]=false;
			if(a[i]<=q)++sum[i];
		}
		int ans=0,pos,now=0,cnt=0;
		for(int i=n;i>=1;--i){
			if(a[i]<=q){
				++cnt;
				if(q-a[i]+now<=100000)++num[q-a[i]+now];
				if(ans<cnt+now+sum[i-1]){
					ans=cnt+now+sum[i-1];
					pos=i;
				}
			}
			else{
				cnt-=num[now++];
				if(ans<cnt+now+sum[i-1]){
					ans=cnt+now+sum[i-1];
					pos=i;
				}
				if(now==q)break;
			}
		}
		for(int i=1;i<pos;++i){
			if(a[i]<=q)cout<<"1";
			else cout<<"0";
		}
		for(int i=pos;i<=n;++i){
			if(a[i]<=q)cout<<"1";
			else{
				if(q)cout<<"1"
			}
		}
	}
	
	
	return 0;
}