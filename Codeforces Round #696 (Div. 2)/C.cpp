#include<bits/stdc++.h>
using namespace std;
int ansx[1005],ansy[1005],a[2005],cnt[1000006],cnttmp[1000006];
bool usd[2005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)scanf("%d",&a[i]),++cnttmp[a[i]];
		sort(a+1,a+1+2*n,cmp);
		cnttmp[0]=0; 
		bool ky=false;
		for(int i=2;i<=2*n;++i){
			for(int j=1;j<=2*n;++j)cnt[a[j]]=cnttmp[a[j]];
			ansx[1]=a[1],ansy[1]=a[i];
			--cnt[a[1]],--cnt[a[i]];
			int tot=a[1],num=1;
			for(int j=2;j<=2*n;++j){
				if(cnt[a[j]]){
					--cnt[a[j]];
					if(cnt[tot-a[j]]){
						++num;
						ansx[num]=a[j];
						ansy[num]=tot-a[j];
						--cnt[tot-a[j]];
						tot=a[j];
					}
					else break;
				}
				if(num==n)break;
			}
			if(num==n){
				ky=true;
				printf("YES\n%d\n",ansx[1]+ansy[1]);
				for(int j=1;j<=n;++j)printf("%d %d\n",ansx[j],ansy[j]);
				break; 
			}
		}
		if(!ky)printf("NO\n");
		for(int i=1;i<=2*n;++i)--cnttmp[a[i]],cnt[a[i]]=0;
	}
	return 0;
}
