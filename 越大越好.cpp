#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,x;
	cin>>a>>b>>x;
	if(a*1000000000+b*9<=x)return !printf("1000000000\n");
	int now=1000000000;
	for(int i=8;i>=1;--i){
		now/=10;
		long long re=(x-b*i)/a;
		if(re<now)continue;
		if(re>=now*10)re=now*10-1;
		return !printf("%lld\n",re);
	}
	cout<<"0\n";
	
	return 0;
}