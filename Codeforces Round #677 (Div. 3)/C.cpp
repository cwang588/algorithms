#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int Max=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),Max=max(Max,a[i]);
		bool ky=false;
		a[0]=a[n+1]=2147483647;
		for(int i=1;i<=n;++i){
			if((a[i]>a[i-1]||a[i]>a[i+1])&&a[i]==Max){
				printf("%d\n",i);
				ky=true;
				break;
			}
		}
		if(!ky)printf("-1\n");
	}
	return 0;
}
