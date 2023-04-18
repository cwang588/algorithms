#include<bits/stdc++.h>
using namespace std;
long long a[200005],Min1[200005],Min2[200005],tot1[200005],tot2[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tot1[0]=tot2[n+1]=0;
		Min1[0]=Min2[n+1]=1e18;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			tot1[i]=a[i]-tot1[i-1];
			Min1[i]=min(Min1[i-1],tot1[i]);
		}
		for(int i=n;i>=1;--i){
			tot2[i]=a[i]-tot2[i+1];
			Min2[i]=min(Min2[i+1],tot2[i]);
		}
		if(tot1[n]==0&&Min1[n]==0){
			cout<<"YES\n";
			continue;
		}
		bool ky=false;
		for(int i=1;i<n;++i){
			if(Min1[i-1]<0)break;
			if(Min2[i+2]<0)continue;
			if(a[i+1]>=tot1[i-1]&&a[i]>=tot2[i+2]&&a[i+1]-tot1[i-1]==a[i]-tot2[i+2]){
				ky=true;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}