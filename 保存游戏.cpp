#include<bits/stdc++.h>
using namespace std;
int x[1000005],fa[1000005][25],mi[25];
int main(){
	int n;
	cin>>n;
	mi[0]=1;
	for(int i=1;i<=20;++i)mi[i]=mi[i-1]*2;
	for(int i=1;i<=n;++i)cin>>x[i];
	x[n+1]=2147483647;
	int L;
	cin>>L;
	for(int i=0;i<=20;++i)fa[n+1][i]=n+1;
	for(int i=1;i<n;++i)fa[i][0]=upper_bound(x,x+n+1,x[i]+L)-x-1;
	fa[n][0]=n+1;
	for(int i=1;i<=20;++i){
		for(int j=1;j<=n;++j)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int m; 
	cin>>m;
	for(int i=1;i<=m;++i){
		int l,r;
		cin>>l>>r;
		if(l>r)swap(l,r);
		int ans=0,now=l;
		for(int j=20;j>=0;--j){
			if(fa[now][j]<=r){
				now=fa[now][j];
				ans+=mi[j];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
