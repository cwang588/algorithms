#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],cnt[1005][1005][4];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
				for(int k=0;k<=3;++k)cnt[i][j][k]=0;
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]==0)continue;
				cnt[i][j][0]=cnt[i][j-1][0]+1;
			}
			cnt[i][m+1][1]=a[i][m+1]=0;
			for(int j=m;j>=1;--j){
				if(a[i][j]==0)continue;
				cnt[i][j][1]=cnt[i][j+1][1]+1;
			}
		}
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(a[j][i]==0)continue;
				cnt[j][i][2]=cnt[j-1][i][2]+1;
			}
			cnt[n+1][i][3]=a[n+1][i]=0;
			for(int j=n;j>=1;--j){
				if(a[j][i]==0)continue;
				cnt[j][i][3]=cnt[j+1][i][3]+1;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(a[i][j]==0)continue;
				ans+=max(1,min(cnt[i][j][0]/2,cnt[i][j][2]))-1;
				ans+=max(1,min(cnt[i][j][2]/2,cnt[i][j][0]))-1;
				ans+=max(1,min(cnt[i][j][0]/2,cnt[i][j][3]))-1;
				ans+=max(1,min(cnt[i][j][3]/2,cnt[i][j][0]))-1;	
				ans+=max(1,min(cnt[i][j][1]/2,cnt[i][j][2]))-1;
				ans+=max(1,min(cnt[i][j][2]/2,cnt[i][j][1]))-1;
				ans+=max(1,min(cnt[i][j][1]/2,cnt[i][j][3]))-1;
				ans+=max(1,min(cnt[i][j][3]/2,cnt[i][j][1]))-1;		
			}
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	
	
	return 0;
}