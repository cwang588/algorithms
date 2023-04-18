#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n); 
		int pos=0;
		for(int i=2;i<=n;++i){
			if(a[i]!=a[1]){
				pos=i;
				break;
			}
		}
		if(!pos){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		cout<<a[1]<<" ";
		for(int i=pos;i<=n;++i)cout<<a[i]<<" ";
		for(int i=2;i<pos;++i)cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}