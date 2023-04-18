#include<bits/stdc++.h>
using namespace std;
int a[30005],b[30005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		a[n+1]=0;
		if(n==1){
			printf("YES\n");
			continue;
		}
		b[1]=a[1];
		b[n+1]=-a[n];
		int tot1=0,tot2=0;
		for(int i=2;i<=n;++i){
			b[i]=a[i]-a[i-1];
			if(b[i]>0)tot1-=b[i];
			else tot2-=b[i];
		}
		if(b[1]>=tot2&&b[n+1]<=tot1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
