#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
		bool ky=false;
		for(int i=1;i<=n;++i){
			long long now=sqrt(a[i]);
			if(now*now!=a[i]){
				ky=true;
				break;
			}
		}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
