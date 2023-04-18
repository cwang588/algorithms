#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=n+1;i<=n*3;++i){
		int now=0;
		for(int j=i-n;j<i;++j)now^=a[j];
		a[i]=now;
	}
	for(int i=1;i<=n*3;++i)cout<<a[i]<<" ";
	return 0;
}
