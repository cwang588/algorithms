#include<bits/stdc++.h>
using namespace std;
int cnt[25];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,w;
		scanf("%d%d",&n,&w);
		for(int i=1;i<=n;++i){
			int now;
			scanf("%d",&now);
			int num=0;
			while(now){
				++num;
				now>>=1;
			}	
			++cnt[num-1];
		}
		int re=n,ans;
		for(ans=1;;++ans){
			int tot=w;
			for(int i=20;i>=0;--i){
				int tmp=(1<<i);
				while(tot>=tmp&&cnt[i]){
					--cnt[i];
					tot-=tmp;
					--re;
				}		
			}
			if(!re)break;
		}
		printf("%d\n",ans);
	} 
	return 0;
}
