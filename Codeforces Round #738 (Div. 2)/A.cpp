#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=2147483647;
		while(n--){
			int tmp;
			cin>>tmp;
			ans&=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
