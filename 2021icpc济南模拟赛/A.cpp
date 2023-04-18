#include<bits/stdc++.h>
using namespace std;
int pre[65],a[65],b[65],c[65];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>pre[i];
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)cin>>b[i];
	for(int i=1;i<=n;++i)c[i]=a[i]+b[i];
	for(int i=1;i<n;++i){
		if(c[i]>=0){
			int now=c[i]/2;
			c[i]%=2;
			if(pre[i+1]==pre[i])c[i+1]+=now;
			else c[i+1]-=now;
		}
		else{
			c[i]=1;
			if(pre[i+1]!=pre[i])++c[i+1];
			else --c[i+1];
		}
	}
	for(int i=1;i<n;++i)cout<<c[i]<<" ";
	cout<<c[n];
	//cout<<"\n";
	return 0;
}