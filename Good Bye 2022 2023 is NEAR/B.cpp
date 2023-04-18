#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int now1=n,now2=1;
		for(int i=1;i<=n;++i){
			if(i%m)cout<<now1--<<" ";
			else cout<<now2++<<" ";
		}
		cout<<"\n";
	}
	
	
	return 0;
}