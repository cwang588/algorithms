#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long sum[500005];
int lowbit(int x){
	return x&(-x);
}
int n;
void modify(int pos,int x){
	while(pos<=n){
		sum[pos]+=x;
		pos+=lowbit(pos);	
	}
}
long long query(int x){
	long long ans=0;
	while(x){
		ans+=sum[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),modify(i,a[i]);
	for(int i=1;i<=m;++i){
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==1)modify(x,y);
		else printf("%lld\n",query(y)-query(x-1));
	}
	return 0;
}
