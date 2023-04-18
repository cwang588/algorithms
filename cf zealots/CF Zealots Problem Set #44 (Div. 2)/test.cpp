#include<bits/stdc++.h>
using namespace std;
int a[100000005];
long long sum[100000005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		auto t=clock();
		for(int i=1;i<=n;++i)a[i]=100;
		for(int i=1;i<=n;++i)sum[i]=100;
		cout<<clock()-t<<"\n";
		t=clock();
		for(int i=1;i<=n;++i)a[i]=100,sum[i]=100;
		cout<<clock()-t<<"\n";
	}
	
	return 0;
}