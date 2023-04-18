#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long tot=0,Max=0; 
		for(int i=1;i<=n;++i){
			long long tmp;
			cin>>tmp;
			tot+=tmp;
			Max=max(Max,tmp);	
		}
		if(n==2){
			printf("0\n");
			continue;
		}
		if(Max*(n-1)>=tot)printf("%I64d\n",Max*(n-1)-tot);
		else printf("%I64d\n",(n-1-(tot-Max*(n-1))%(n-1))%(n-1));
	}
	return 0;
}
