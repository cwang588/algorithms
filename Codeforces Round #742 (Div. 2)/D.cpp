#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int s,n;
		cin>>s>>n;
		int now=1000000000;
		while(now>s)now/=10;
		while(now>1){
			while(n>1&&s-now>=n-1){
				s-=now;
				cout<<now<<" ";
				--n;
			}
			now/=10;
		}
		for(int i=1;i<n;++i){
			cout<<"1 ";
			--s;
		}
		if(s)cout<<s<<endl;
	}
	return 0;
}
