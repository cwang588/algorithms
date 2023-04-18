#include<bits/stdc++.h>
using namespace std;
int a[200005],col[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i],col[i]=0;
		int ans=n;
		for(int i=1;i<=n;++i){
			if(col[i])continue;
			col[i]=++cnt;
			int now=a[i];
			while(!col[now]){
				col[now]=cnt;
				now=a[now];
			}
			--ans;
		}
		bool ky=false;
		for(int i=1;i<n;++i){
			if(col[i]==col[i+1]){
				ky=true;
				break;
			}
		}
		if(ky)--ans;
		else ++ans;
		cout<<ans<<"\n";
	}
	
	return 0;
}