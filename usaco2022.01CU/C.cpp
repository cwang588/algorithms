#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
int n;
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=2;i<=n;++i)b[i]=a[i]-a[i-1];
		bool ky=true;
		long long ans=0;
		if(n>=3&&b[3]<0){
			ans-=b[3]*2;
			a[1]+=b[3],a[2]+=b[3];
			b[3]=0;
		}
		for(int i=2;i<n;++i){
			if(b[i]<0){	
				ky=false;
				break;
			}
			else{
				ans+=b[i]*2;
				a[i]-=b[i],a[i+1]-=b[i];	
				b[i+2]+=b[i];
				b[i]=0;
			}
		}
		if(n%2){
			if(b[n]<0){
				for(int i=1;i<n;++i)a[i]+=b[n];
				ans-=b[n]*(n-1);
				b[n]=0;
			}
		}
		if(!ky||b[n]!=0){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=n;++i){
			if(a[i]<0){
				ky=false;
				break;
			}
		}
		if(ky)cout<<ans<<"\n";
		else cout<<"-1\n";
	}
	
	
	return 0;
}