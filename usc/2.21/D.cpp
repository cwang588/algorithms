#include<bits/stdc++.h>
using namespace std;
int sum[15];
long long tot[25],mi[25];
long long calc(long long x){
	if(x<=0)return 0;
	vector<int>a;
	while(x){
		a.push_back(x%10);
		x/=10;
	}
	reverse(a.begin(),a.end());
	int n=a.size(),now=0;
	long long re=0;
	for(int i=0;i<n;++i){
		re+=(now*a[i]+sum[a[i]]-a[i])*mi[n-i-1]+tot[n-i-1]*a[i];
		now+=a[i];
	}
	re+=now;
	return re;
}
int main(){
	mi[0]=1;
	for(int i=1;i<=15;++i)tot[i]=tot[i-1]*10+45*mi[i-1],mi[i]=mi[i-1]*10;
	for(int i=1;i<=9;++i)sum[i]=sum[i-1]+i;
	long long l,r;
	int n;
	cin>>n;
	while(n--){
		cin>>l>>r;
		cout<<calc(r)-calc(l-1)<<"\n";
	}
	return 0;
}