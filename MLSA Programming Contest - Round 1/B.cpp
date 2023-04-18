#include<bits/stdc++.h>
using namespace std;
const int inf=2147483647;
int a[10004],w[10005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		swap(n,m);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;++i)cin>>a[i];
		int ans=0;
		for(int i=1;i<=m;++i)w[i]=a[i],ans=max(ans,a[i]);
		for(int i=m+1;i<=n;++i){
			int Min=inf,pos;
			for(int j=1;j<=m;++j){
				if(Min>w[j]){
					Min=w[j];
					pos=j;
				}
			}
			w[pos]+=a[i];
			ans=max(ans,w[pos]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
