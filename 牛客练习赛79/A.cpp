#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int ans=0,Max=0;
	for(int i=n;i>=1;--i){
		if(a[i]>Max){
			++ans;
			Max=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
