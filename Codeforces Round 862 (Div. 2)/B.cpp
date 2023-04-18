#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		int pos=0;
		for(int i=0;i<26;++i){
			for(int j=n;j>=1;--j){
				if(a[j]=='a'+i){
					pos=j;
					break;
				}
			}
			if(pos)break;
		}
		cout<<a[pos];
		for(int i=1;i<=n;++i){
			if(i!=pos)cout<<a[i];
		}
		cout<<"\n";
	}
	
	return 0;
} 
