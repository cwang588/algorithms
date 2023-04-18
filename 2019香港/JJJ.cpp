#include<bits/stdc++.h>
using namespace std;
int f(int x){
	int tot1=0,tot2=0;
	while(x){
		int now=x%10;
		tot1+=now;
		tot2+=now*now;
		x/=10;
	}
	return (tot1*tot1-tot2)/2;
}
int main(){
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int i=0;i<=n;++i)if(i%m==f(i)%m)++ans,printf("%d ",i);
	printf("%d\n",ans);
	return 0;
}
