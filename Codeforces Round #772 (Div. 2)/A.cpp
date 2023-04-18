#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		while(n--){
			int tmp;
			cin>>tmp;
			ans|=tmp;
		}
		cout<<ans<<"\n";
	}
	return 0;
}