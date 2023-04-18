#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		long long x,y;
		cin>>n>>x>>y;
		x&=1,y&=1;
		int now=0;
		while(n--){
			long long tmp;
			cin>>tmp;
			now^=(tmp&1);
		}
		if(x^now==y)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
	return 0;
}