#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,A;
		cin>>n>>A;
		if(n-2>A){
			cout<<"Case #"<<Case<<": IMPOSSIBLE\n";
			continue;
		}
		cout<<"Case #"<<Case<<": POSSIBLE\n";
		for(int i=1;i*2<n;++i){
			if(i%2)cout<<i-1<<" 0\n";
			else cout<<i-1<<" 1\n";
		}
		if(n-2==A){
			if(n%2)cout<<n/2<<" 1\n";
			else{
				int tmp=n/2;
				if(tmp%2){
					cout<<tmp-1<<" 0\n";
					cout<<tmp-1<<" 1\n";
				}
				else{
					cout<<tmp-1<<" 1\n";
					cout<<tmp-1<<" 2\n";
				}
			}
		}
		else{
			if(n%2)cout<<A-n+2+n/2<<" 1\n";
			else{
				int tmp=n/2-1;
				if(tmp%2){
					cout<<tmp<<" 0\n";
					cout<<A-n+2+tmp<<" 1\n";
				}
				else{
					cout<<tmp<<" 1\n";
					cout<<A-n+2+tmp<<" 2\n";
				}
			}
		}
		for(int i=(n-1)/2;i>=1;--i){
			if(i%2)cout<<i-1<<" 1\n";
			else cout<<i-1<<" 2\n";
		}
	}
	
	return 0;
}