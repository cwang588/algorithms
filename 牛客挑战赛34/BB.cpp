#include<bits/stdc++.h>
using namespace std;
int calc1(long long tot)
{
	long long t=1;
	for(int i=1;;++i)
	{
		t*=2;
		if(t>tot)return i-1;
	}
}
int calc2(long long tot)
{
	long long t=1;
	for(int i=1;;++i)
	{
		t*=2;
		if(t>=tot)return i-1;
	}
}
long long mi(int x)
{
	long long re=1;
	for(int i=1;i<=x;++i)re*=2;
	return re;
}
int main()
{
	long long n,m;
	cin>>n>>m;
	if(m%2==0)return !printf("0 0\n");
	int x=calc1(n+1),y=calc2(m+1);
	long long z=n+1-mi(x);
	int ans=x-y;
	long long index;
	if(2*z-1>=m)
	{
		++ans;
		index=mi(x)-1+(m+1)/2;
	}
	else index=mi(x-1)-1+(m+1)/2;
	if(ans==0)index=0;
	cout<<ans<<' '<<index<<endl;
	return 0;
}
