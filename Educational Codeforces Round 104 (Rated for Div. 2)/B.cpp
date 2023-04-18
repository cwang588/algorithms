#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		int ans;
		if(n%2==0)ans=k%n;
		else ans=(k+(k-1)/((n-1)/2))%n;
		if(!ans)ans=n;
		printf("%d\n",ans);
	}
	return 0;
}
