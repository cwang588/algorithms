#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	int n,m;
	long long h;
	cin>>n>>m>>h;
	for(int i=1;i<=n;++i){
		long long x,y;
		cin>>x>>y;
		a[i]=max(0ll,(h-x-1)/y+1);
	}
	sort(a+1,a+1+n);
	cout<<a[m];
	return 0;
}
