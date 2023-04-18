#include<bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(a<b)
		swap(a,b);
	return b?gcd(b,a%b):a;
}
struct fs
{
	unsigned long long x,y;
}f[56];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		cin>>f[i].x>>f[i].y;
	fs ans;
	ans.x=0;
	ans.y=1;
	for(int i=1;i<=n;++i)
	{
		unsigned long long t1,t2;
		t1=ans.x*f[i].y+ans.y*f[i].x;
		t2=ans.y*f[i].y;
		unsigned long long t3=gcd(t1,t2);
		ans.x=t1/t3;
		ans.y=t2/t3;
	}
	cout<<ans.x<<' '<<ans.y;
	return 0;
}
