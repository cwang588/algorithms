#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
bool check(int num){
	long long x=0,y=0;
	for(int i=1;i<=n;++i){
		if(num>=a[i])x+=(num-a[i])>>1;
		else y+=a[i]-num;
	}
	return x>=y;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)a[i]=0;
		for(int i=1;i<=m;++i){
			int tmp;
			cin>>tmp;
			++a[tmp];
		}
		int l=0,r=500000;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
	
	
	return 0;
}