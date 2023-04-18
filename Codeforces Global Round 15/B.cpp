#include<bits/stdc++.h>
using namespace std;
struct ath{
	int r[7],id;
	operator < (const ath &b){
		int cnt=0;
		for(int i=1;i<=5;++i)if(r[i]<b.r[i])++cnt;
		return cnt>=3;
	}
}a[50005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=5;++j)cin>>a[i].r[j],a[i].id=i;
		}
		sort(a+1,a+1+n);
		bool ky=true;
		for(int i=2;i<=n;++i){
			if(a[i]<a[1]){
				ky=false;
				break;
			}
		}
		if(!ky)cout<<"-1"<<endl;
		else cout<<a[1].id<<endl;
	}
	return 0;
}
