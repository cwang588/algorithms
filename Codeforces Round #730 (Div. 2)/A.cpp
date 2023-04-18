#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		if(a<b)swap(a,b);
		if(a==b)cout<<"0 0"<<endl;
		else cout<<a-b<<" "<<min(b%(a-b),a-b-b%(a-b))<<endl;
	}
	return 0;
}
