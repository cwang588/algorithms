#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005]; 
int n,m;
long long getmax(int i){
	return max(a[i]*b[1],a[i]*b[m]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	if(getmax(1)>getmax(n))cout<<a[1]<<" "<<max(getmax(2),getmax(n))<<endl;
	else cout<<a[n]<<" "<<max(getmax(1),getmax(n-1))<<endl;
	return 0;
}
