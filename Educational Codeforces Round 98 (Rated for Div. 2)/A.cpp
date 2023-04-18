#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=2*abs(min(x,y))+2*abs(x-y)-1;
		if(x==y)++ans;
		printf("%d\n",ans);
	}
	return 0;
}
