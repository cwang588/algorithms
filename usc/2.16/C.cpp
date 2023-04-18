#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,cnta=0,cntb=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			int x;
			char y;
			cin>>x>>y;
			if(y=='B')a[++cnta]=x;
			else b[++cntb]=x;
		}
		sort(a+1,a+cnta+1);
		sort(b+1,b+cntb+1);
		reverse(a+1,a+cnta+1);
		reverse(b+1,b+cntb+1);
		int ans=0;
		for(int i=1;i<=min(cnta,cntb);++i){
			ans+=a[i]+b[i]-2;
		}
		cout<<"Case #"<<Case<<": "<<ans<<"\n";
	}
	
	return 0;
}