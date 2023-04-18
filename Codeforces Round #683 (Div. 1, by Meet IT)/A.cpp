#include<bits/stdc++.h>
using namespace std;
struct number{
	long long w;
	int id;
	bool usd;
}a[200005];
bool cmp(number x,number y){
	return x.w>y.w;
}
int ans[200005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		long long v;
		scanf("%d%I64d",&n,&v);
		for(int i=1;i<=n;++i)scanf("%I64d",&a[i].w),a[i].id=i,a[i].usd=false;
		sort(a+1,a+n+1,cmp);
		long long tot=0;
		bool ky=false;
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(a[i].w>v)continue;
			if(a[i].w*2>=v){
				printf("1\n%d\n",a[i].id);
				ky=true;
				break;
			}
			if((tot+a[i].w<=v&&(tot+a[i].w)*2>=v)){
				ans[++cnt]=a[i].id;
				tot+=a[i].w;
				break;
			}
			if(tot+a[i].w>v)continue;
			ans[++cnt]=a[i].id;
			tot+=a[i].w;
		}
		if(ky)continue;
		if(!cnt||tot*2<v)printf("-1\n");
		else{
			printf("%d\n",cnt);
			sort(ans+1,ans+1+cnt);
			for(int i=1;i<=cnt;++i)printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
