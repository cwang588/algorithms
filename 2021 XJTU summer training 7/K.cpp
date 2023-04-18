#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	int Case=0; 
	while(cin>>n>>k){
		if(k<=n){
			printf("Case #%d: %lld\n",++Case,k);
			continue;
		}
		long long a=k/(n-1),b=k%(n-1);
		if(!b)b=n-1;
		else ++a;
		a%=2;
		if(a){
			if(b==1)printf("Case #%d: %lld\n",++Case,n-1);
			else printf("Case #%d: %lld\n",++Case,b-1);
		}
		else{
			if(b==1)printf("Case #%d: %lld\n",++Case,n);
			else printf("Case #%d: %lld\n",++Case,b-1);
		}
	}
	
	return 0;
}
