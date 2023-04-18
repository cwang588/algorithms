#include<bits/stdc++.h>
using namespace std;
int a[45];
int main(){
	int n;
	cin>>n;
	long long ans=0,num=1;
	for(int i=1;i<n;++i)num*=2;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ans+=num*a[i];
	}
	for(int i=1;i<=n;++i)if(a[i]<200)ans-=a[i];
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i]+a[j]<200)ans-=a[i]+a[j];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			for(int k=j+1;k<=n;++k){
				if(a[i]+a[j]+a[k]<200)ans-=a[i]+a[j]+a[k];
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}