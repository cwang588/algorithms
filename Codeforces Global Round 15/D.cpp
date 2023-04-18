#include<bits/stdc++.h>
using namespace std;
int a[15],n;
bool dfs(int now,int id,int tot){
	if(now==n+1)return a[id]==tot;
	if(now!=id)return dfs(now+1,id,tot)|dfs(now+1,id,tot+a[now])|dfs(now+1,id,tot-a[now]);
	return dfs(now+1,id,tot);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool ky=false;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(!a[i])ky=true;
		}
		if(ky){
			cout<<"YES\n";
			continue;
		}
		for(int i=1;i<=n;++i){
			if(dfs(1,i,0)){
				cout<<"YES\n";
				ky=true;
				break;
			}
		}
		if(!ky)cout<<"NO\n";		
	} 
	return 0;
}
