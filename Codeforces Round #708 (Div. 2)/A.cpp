#include<bits/stdc++.h>
using namespace std;
int a[105],cnt[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<=100;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),++cnt[a[i]];
		for(int i=0;i<n;++i){
			if(cnt[i]){
				printf("%d ",i);
				--cnt[i];
			}
			else break;
		}
		for(int i=0;i<=100;++i){
			while(cnt[i]){
				printf("%d ",i);
				--cnt[i];
			}
		}
		printf("\n");
	}
	return 0;
}
