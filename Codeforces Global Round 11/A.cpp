#include<bits/stdc++.h>
using namespace std;
int a[55];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int now1=0,now2=0;
		for(int i=1;i<=n;++i){
			if(a[i]>0)now1+=a[i];
			else now2+=a[i];
		}
		if(now1+now2==0){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(now1+now2<0){
			for(int i=1;i<=n;++i)printf("%d ",a[i]);
			printf("\n");
		}
		else{
			for(int i=n;i>=1;--i)printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}
