#include<bits/stdc++.h>
using namespace std;
int a[105],col[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=1,now=1;
		for(int i=2;i<=n;++i){
			if(a[i]==a[i-1])++now;
			else{
				ans=max(ans,now);
				now=1;
			}
		}
		ans=max(ans,now);
		printf("%d\n",ans);
	}
	return 0;
}
