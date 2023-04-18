#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int num=0;
		for(int i=1;i<=n;++i){
			if(a[i]>a[1])++num;
		}
		printf("%d\n",num);
	}
	return 0;
}
