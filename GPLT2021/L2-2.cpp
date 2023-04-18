#include<bits/stdc++.h>
using namespace std;
int cnt[1000005];
int main(){
	int n,Max=0,Min=2147483647;
	cin>>n;
	for(int i=1;i<=n;++i){
		int t;
		cin>>t;
		++cnt[t]; 
		Max=max(Max,t);
		Min=min(Min,t);
	}
	printf("%d %d\n%d %d\n",Min,cnt[Min],Max,cnt[Max]);
	return 0;
}
