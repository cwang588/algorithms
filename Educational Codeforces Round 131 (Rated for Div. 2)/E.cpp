#include<bits/stdc++.h>
using namespace std;
char a[5005],b[5005];
int lpos[5005],rpos[5005],dpl[5005][5005],dpr[5005][5005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		cin>>(a+1)>>(b+1);
		int now=1,bound=0;
		for(int i=1;i<=n;++i){
			if(a[i]!=b[now]&&!bound)bound=i;
			if(a[i]==b[now])lpos[now++]=i;
			if(now>m)break;
		}
		if(now<=m){
			cout<<"-1\n";
			continue;
		}
		if(!bound)bound=m+1;
		--bound;
		now=m;
		rpos[m+1]=n+1;
		for(int i=n;i>=1;--i){
			if(a[i]==b[now])rpos[now--]=i;
			if(now<1)break;
		}
		int ans=max(0,n-bound);
		for(int i=n;i>=1;--i){
			for(int j=m;j>=1;--j){
				if(a[i]==b[j])dpl[i][j]=dpl[i+1][j+1]+1;
				else dpl[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=0;j<=m;++j){
				if(lpos[j]>i||rpos[j+1]<=i)continue;
				int nowans=n-i-dpl[i+1][j+1]+1+i*2-min(bound,min(i,j));
				ans=min(ans,nowans);
			}
		}
		for(int i=1;i<=n+1;++i){
			for(int j=1;j<=m+1;++j)dpl[i][j]=0;
		}
		for(int i=1;i<=n;++i)lpos[i]=rpos[i]=0;
		cout<<ans<<"\n";
	}
	
	return 0;
}