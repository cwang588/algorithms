#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
bool usd[100005];
map<int,int>pos;
int main(){
	b[0]=2147483647;
	int t;
	cin>>t;
	while(t--){
		pos.clear();
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;++i)pos[a[i]]=i;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(b[i]<b[i-1]||pos[b[i]]!=pos[b[i-1]]+1)
				++cnt;
		}
		if(cnt>k)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
