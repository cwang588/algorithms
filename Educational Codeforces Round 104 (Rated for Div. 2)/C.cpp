#include<bits/stdc++.h>
using namespace std;
int cnt[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(n%2){
			for(int i=1;i<=n;++i)cnt[i]=n/2*3;
		}
		else{
			for(int i=1;i<=n;++i)cnt[i]=n/2*3-2;
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(cnt[i]>=3){
					printf("1 ");
					cnt[i]-=3;
				}
				else if(cnt[i]>0){
					printf("0 ");
					--cnt[i];
					--cnt[j];
				}
				else{
					printf("-1 ");
					cnt[j]-=3;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
