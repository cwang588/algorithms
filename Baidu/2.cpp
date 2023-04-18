#include<bits/stdc++.h>
using namespace std;
char a[]={'r','e','d'};
int get_num(long long x){
	long long l=1,r=x;
	while(l<r-1){
		long long m=(l+r)>>1;
		if(m*(m+1)/2<=x)l=m;
		else r=m;
	}
	return l;
}
int main(){
	long long n;
	cin>>n;
	int now=0;
	while(n){
		int num=get_num(n);
		n-=(num+1)*num/2;
		for(int i=1;i<=num;++i)cout<<a[now];
		now=(now+1)%3;
	}
	cout<<"\n";
	return 0;
}