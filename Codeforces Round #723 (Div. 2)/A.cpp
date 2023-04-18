#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i)scanf("%d",&a[i]);
		sort(a+1,a+1+2*n);
		for(int i=1;i<=n;++i)printf("%d %d ",a[i],a[2*n-i+1]);
		printf("\n");
	}
	return 0;
}
