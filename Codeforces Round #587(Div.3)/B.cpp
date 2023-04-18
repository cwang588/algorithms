#include<bits/stdc++.h>
using namespace std;
pair<int,int>a[1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].first,a[i].second=i;
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int tot=0;
	for(int i=1;i<=n;++i){
		tot+=(i-1)*a[i].first+1;
	}
	cout<<tot<<'\n';
	for(int i=1;i<=n;++i)cout<<a[i].second<<" ";
	return 0;
}