#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		if(a[1]){
			cout<<n+1<<" ";
			for(int i=1;i<=n;++i)cout<<i<<" "; 
		}
		else{
			bool ky=false;
			for(int i=2;i<=n;++i){
				if(a[i]){
					ky=true;
					for(int j=1;j<i;++j)cout<<j<<" ";
					cout<<n+1<<" ";
					for(int j=i;j<=n;++j)cout<<j<<" ";
					break;
				}
			}
			if(!ky){
				for(int i=1;i<=n+1;++i)cout<<i<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}
