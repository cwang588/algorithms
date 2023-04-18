#include<bits/stdc++.h>
using namespace std;
int a[75][75];
int main(){
	int n,m,cnt0=0,cnt1=0,cnt2=0;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
			if(!a[i][j])++cnt0;
			else if(a[i][j]==2)++cnt2;
			else ++cnt1;
		}
	}
	if(cnt0>=2){
		cout<<"0\n";
	}else if(cnt0==1){
		if(n>1&&m>1){
			if(cnt1)cout<<"1\n";
			else cout<<"2\n";
		}else{
			if(n==1){
				if(a[1][1]!=1&&a[1][m]!=1)cout<<"2\n";
				else cout<<"1\n";
			}else{
				if(a[1][1]!=1&&a[n][1]!=1)cout<<"2\n";
				else cout<<"1\n";
			}
		}
	}else{
		if(cnt2%2==0)cout<<"0\n";
		else{
			long long ans=1;
			for(int i=1;i<=cnt2/2;++i)ans*=2;
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}