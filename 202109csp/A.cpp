#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	long long ans1=0,ans2=0;
	a[0]=-1;
	for(int i=1;i<=n;++i){
		ans1+=a[i];
		if(a[i]!=a[i-1])ans2+=a[i];	
	}
	cout<<ans1<<"\n"<<ans2<<"\n";
	return 0;
}