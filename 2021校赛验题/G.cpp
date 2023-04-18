#include<bits/stdc++.h>
using namespace std;
int cnt[205];
int main(){
	int n;
	scanf("%d",&n);
	long long ans=0;
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		tmp%=200;
		ans+=cnt[tmp];
		++cnt[tmp];	
	}
	printf("%lld\n",ans);
	return 0; 	
}
