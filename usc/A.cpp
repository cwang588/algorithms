#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	int h,w,n;
	cin>>h>>w>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	int now=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(now+a[i]>w)break;
		now+=a[i];
		if(now==w){
			++cnt;
			now=0;
		}
	}
	if(cnt>=h)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}