#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;	
	scanf("%d",&t);
	while(t--){
		int n,k1,k2,w,b;
		scanf("%d%d%d%d%d",&n,&k1,&k2,&w,&b);
		if(min(k1,k2)+abs(k1-k2)/2>=w&&min(n-k1,n-k2)+abs(k1-k2)/2>=b)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
