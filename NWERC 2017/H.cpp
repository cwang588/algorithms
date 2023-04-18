#include<bits/stdc++.h>
using namespace std;
long long calc(long long a,long long b,long long c){
	return a*a+b*b+c*c+min(a,min(b,c))*7;
}
int main(){
	int n;
	cin>>n;
	while(n--){
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a<b)swap(a,b);
		if(b<c)swap(b,c);
		if(a<b)swap(a,b);
		if(d>=10000){
			cout<<(a+d)*(a+d)+b*b+c*c+c*7<<endl;
			continue;
		}
		long long ans=0;
		for(int i=0;i<=d;++i){
			for(int j=0;i+j<=d;++j){
				ans=max(ans,calc(a+i,b+j,c+d-i-j));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
