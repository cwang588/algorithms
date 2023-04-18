#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,now=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			int tmp;
			cin>>tmp;
			now^=tmp;
		}
		if(!now)cout<<"0\n";
		else{
			if(n%2==0)cout<<"-1\n";
			else cout<<now<<"\n"; 
		}
	}
	
	return 0;
} 
