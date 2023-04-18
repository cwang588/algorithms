#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			cout<<"1\n";
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			if(a[i]==1)++cnt;
		}
		if(cnt>n-cnt)cout<<n-cnt<<"\n";
		else cout<<n/2<<"\n";
	}
	return 0;
}