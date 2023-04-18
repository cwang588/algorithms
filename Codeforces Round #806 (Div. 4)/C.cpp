#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i){
			int m;
			cin>>m;
			while(m--){
				char tmp;
				cin>>tmp;
				if(tmp=='U')--a[i];
				else ++a[i];
			}
		}
		for(int i=1;i<=n;++i)cout<<(a[i]%10+10)%10<<" ";
		cout<<"\n";
	}
	
	
	
	return 0;
}