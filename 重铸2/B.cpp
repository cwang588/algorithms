#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[1000005],p[1000005];
long long cmp(long long x,long long y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=n;++i)cin>>b[i];
		for(int i=1;i<=n;++i)p[i]=b[i]-a[i];
		if(n==2){
			if(p[1]&&!p[2])printf("YES\n");
			else printf("NO\n");
			continue;
		}
		sort(p+2,p+n+1,cmp);
		long long tot=p[1];
		bool ky=true;
		for(int i=2;i<=n;++i){
			if(tot<1){
				printf("NO\n");
				ky=false;
				break;
			}
			tot+=p[i]-1;
		}	
		if(ky)printf("YES\n");
	}
	return 0;
}
