#include<bits/stdc++.h>
using namespace std;
int a[105],ans[1005][1005];
bool dp[105][105],dpp[105][105];
bool cmp(int x,int y){
	if(x==y)return false;
	if(ans[x][y]>-1)return ans[x][y]==1?true:false;
	cout<<'1'<<" "<<x<<" "<<y<<endl;
	fflush(stdout);
	int re;
	cin>>re;
	ans[x][y]=re;
	return ans[x][y]==1?true:false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=0;i<n;++i){
			dpp[i][i]=true;
			for(int j=0;j<n;++j){
				ans[i][j]=-1;
			}
		}
		for(int i=0;i<n;++i)a[i+1]=i;
		sort(a+1,a+1+n,cmp);
		int now=n;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j)dp[a[i]][a[j]]=true;
		}
		for(int i=n;i>=1;--i){
			now=min(i,now);
			if(now==1)break;
			for(int j=now-1;j>=1;--j){
				cout<<'2'<<" "<<a[i]<<" "<<j<<" ";
				for(int k=1;k<=j;++k)cout<<a[k]<<" ";
				cout<<"\n";
				fflush(stdout);
				int tmp=0; 
				cin>>tmp;
				if(!tmp)break;
				now=j;
				dp[a[i]][a[j]]=true;
			}
		}
	    for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					dp[i][j]|=(dp[i][k]&dp[k][j]);
				}
			}
		}
		cout<<"3"<<endl;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(dp[i][j])cout<<"1";
				else cout<<"0";
			}
			cout<<endl;
		}
		fflush(stdout);
		int bkx;
		cin>>bkx;
	}
	return 0;
}
