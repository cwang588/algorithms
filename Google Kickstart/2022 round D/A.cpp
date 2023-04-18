#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	int t;
	cin>>t;
	for(int Case=1;Case<=t;++Case){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
		long long ans=0;
		for(int i=1;i<m;++i)ans+=a[i];
		if((n+m)%2){
			if((a[(n+m)/2]+a[(n+m)/2+1])%2)printf("Case #%d: %I64d.5\n",Case,ans+(a[(n+m)/2]+a[(n+m)/2+1])/2);
			else printf("Case #%d: %I64d.0\n",Case,ans+(a[(n+m)/2]+a[(n+m)/2+1])/2);
		}else{
			printf("Case #%d: %I64d.0\n",Case,ans+a[(n+m)/2]);
		}
	}
	return 0;
}