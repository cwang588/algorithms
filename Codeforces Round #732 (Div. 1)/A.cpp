#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
long long tot[100005][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;++i)cin>>a[i],++tot[a[i]][i%2];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)--tot[a[i]][i%2];
		bool ky=true;
		for(int i=1;i<=100000;++i){
			if(tot[i][0]<0||tot[i][1]<0){
				ky=false;
				break;
			}
		}
		if(ky)cout<<"YES\n";
		else cout<<"NO\n";
	} 
	return 0;
}
