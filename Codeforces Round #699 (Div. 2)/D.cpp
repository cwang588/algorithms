#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)cin>>a[i][j];
		}
		bool ky1=false,ky2=false;
		pair<int,int>ans1,ans2;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(a[i][j]==a[j][i]){
					ky1=true;
					ans1=make_pair(i,j);
				}
				else{
					ky2=true;
					ans2=make_pair(i,j);
				}
			}
		}
		if(ky1){
			printf("YES\n");
			for(int i=1;i<=m+1;++i){
				if(i%2)printf("%d ",ans[i].first);
				else printf("%d ",ans[i].second);
			}
		}
		else{
			if(m%2)
		}
	}
	return 0;
}
