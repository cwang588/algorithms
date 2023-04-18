#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		a[n+1]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int num=0;
		for(int i=1;i<=k;++i){
			int now=1;
			while(a[now]>=a[now+1]&&now<=n)++now;
			if(now>n){
				printf("-1\n");
				break;
			}
			++a[now];
			if(i==k)printf("%d\n",now);
		}
	}
	return 0;
}
