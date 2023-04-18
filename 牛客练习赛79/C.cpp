#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fib[1005],sum[1005];
int main(){
	fib[1]=1;
	fib[2]=1;
	sum[1]=1;
	sum[2]=2;
	for(int i=3;i<=100;++i){
		fib[i]=fib[i-1]+fib[i-2];
		sum[i]=sum[i-1]+fib[i];
	//	cout<<i<<":"<<fib[i]<<" "<<sum[i]<<"\n";
	}
	ull n;
	cin>>n;
	ull tot=0;
	for(int i=1;;++i){
		if(sum[i]>=n)return !printf("%d\n",i+1);
	}
	return 0;
}
