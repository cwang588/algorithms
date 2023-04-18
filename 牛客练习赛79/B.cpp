#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
	int t;
	scanf("%lld",&t);
	int tot=0;
	bool ky=true;
	while(t--){
		int a,b;
		scanf("%lld%lld",&a,&b);
		int num1=0,num2=0,num3=0,num4=0;
		while(a%3==0){
			++num1;
			a/=3;
		}
		while(a%5==0){
			++num2;
			a/=5;
		}
		while(b%3==0){
			++num3;
			b/=3;
		}
		while(b%5==0){
			++num4;
			b/=5;
		}
		if(a!=b){
			ky=false;
			continue;
		}
		int ans=abs(num2-num4);
		if(num3>num4)num1+=num2-num4;
		else num3+=num4-num2;
		ans+=abs(num1-num3);
		tot+=ans;
	}
	if(!ky)printf("-1\n");
	else printf("%lld\n",tot);
	return 0;
}
