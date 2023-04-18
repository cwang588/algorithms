#include<bits/stdc++.h>
using namespace std;
int a[300005],last[300005],num[300005],ans[300005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans[i]=n+1,num[i]=last[i]=0;
		for(int i=1;i<=n;++i){
			num[a[i]]=max(num[a[i]],i-last[a[i]]);
			last[a[i]]=i;
		}
		for(int i=1;i<=n;++i)num[a[i]]=max(n+1-last[a[i]],num[a[i]]);
		for(int i=n;i>=1;--i)ans[num[i]]=i;
		int Min=n+1;
		for(int i=1;i<=n;++i){
			if(ans[i]==n+1&&Min==n+1)printf("-1 ");
			else if(ans[i]==n+1)printf("%d ",Min);
			else{
				printf("%d ",min(ans[i],Min));
				Min=min(ans[i],Min);
			}
		}
		printf("\n");
	}
	return 0;
}
