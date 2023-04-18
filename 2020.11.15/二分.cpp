#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	sort(b+1,b+1+m);
	for(int i=1;i<=n;++i){
		int l=1,r=m;
		while(l<r-1){
			int mid=(l+r)/2;
			if(b[mid]<a[i])l=mid;
			else r=mid;
		}
		if(b[l]==a[i]||b[r]==a[i])printf("%d ",a[i]);
	}
	return 0;
}
