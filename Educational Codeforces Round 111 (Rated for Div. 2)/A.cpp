#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		for(int i=1;;i+=2){
			if(i<=n){
				++ans;
				n-=i;
			}
			else{
				++ans;
				n=0;
			}
			if(!n)break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
