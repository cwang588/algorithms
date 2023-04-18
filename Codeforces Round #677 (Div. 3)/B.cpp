#include<bits/stdc++.h>
using namespace std;
int a[100005],pos[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int num=0;
		for(int i=1;i<=n;++i)if(a[i])pos[++num]=i;
		int ans=100005;
		for(int i=1;i+num-1<=n;++i)ans=min(ans,abs(pos[1]-i)+abs(pos[num]-(i+num-1)));
		printf("%d\n",ans);
	}
	return 0;
}
