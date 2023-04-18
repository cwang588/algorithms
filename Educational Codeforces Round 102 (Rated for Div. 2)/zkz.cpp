#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		ans^=t;
	}
	printf("%d\n",ans);
	return 0;
}
