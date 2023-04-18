#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)cin>>a[i][j];
		}
		int ans=0;
		if(n%2){
			for(int i=1;i<=(n+1)/2;++i){
				for(int j=1;j<(n+1)/2;++j){
					int cnt=0;
					cnt+=a[i][j]-'0';
					cnt+=a[n-j+1][i]-'0';
					cnt+=a[n-i+1][n-j+1]-'0';
					cnt+=a[j][n-i+1]-'0';
					ans+=min(cnt,4-cnt);
				}
			}
		}
		else{
			for(int i=1;i<=n/2;++i){
				for(int j=1;j<=n/2;++j){
					int cnt=0;
					cnt+=a[i][j]-'0';
					cnt+=a[n-j+1][i]-'0';
					cnt+=a[n-i+1][n-j+1]-'0';
					cnt+=a[j][n-i+1]-'0';
					ans+=min(cnt,4-cnt);
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	
	
	return 0;
}