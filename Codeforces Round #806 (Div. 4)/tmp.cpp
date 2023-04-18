#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
int a[10005];
int solve(int x,int n) {
	rep(i,x,n)swap(a[i],a[i+1]);
	int num=0;
	rep(i,1,n)
		rep(j,1,n-1)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]),num++; 
	return num;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	cout<<solve(m,n)<<"\n";
	return 0;
}