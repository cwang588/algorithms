#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
int main(){
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	bool ky=false;
	int now=0;
	long long ans=0;
	for(int i=1;i<=m;++i){
		while(a[now]<b[i]&&now<=n)++now;
		if(now==n+1)break;
		ans+=a[now];
		++now;
		if(i==m)ky=true;
	}
	if(ky)cout<<ans<<endl;
	else cout<<"GG"<<endl;
	return 0;
} 
