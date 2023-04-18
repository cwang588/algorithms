#include<bits/stdc++.h>
using namespace std;
bool usd[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<"2\n";
		for(int i=1;i<=n;++i)usd[i]=false;
		for(int i=1;i<=n;++i){
			if(!usd[i]){
				int now=i;
				while(now<=n){
					cout<<now<<" ";
					usd[now]=true;
					now<<=1;
				}
			}
		}
		cout<<"\n";
	}
	
	
	return 0;
}