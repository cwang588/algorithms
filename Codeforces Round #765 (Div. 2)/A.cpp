#include<bits/stdc++.h>
using namespace std;
int a[10050];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,l,now=1,ans=0;
		cin>>n>>l;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=l;++i){
			int cnt=0;
			for(int j=1;j<=n;++j){
				if(a[j]&1)++cnt;
				a[j]>>=1;
			}
			if(cnt*2>=n)ans+=now;
			now*=2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}