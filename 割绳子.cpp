#include<bits/stdc++.h>
using namespace std;
int n,k;
double a[10005];
bool judge(double x)
{
	int tot=0;
	for(int i=1;i<=n;++i)tot+=(int)(a[i]/x);
	if(tot>=k)return true;
	return false;
}
void print(double x)
{
	cout<<(int)x<<'.';
	x*=10.0;
	int now=(double)x;
	cout<<now%10;
	x*=10.0;
	now=(double)x;
	cout<<now%10<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	double l=0.0,r=100000.0;
	while(l<r-0.00001)
	{
		double mid=(l+r)/2.0;
		if(judge(mid))l=mid;
		else r=mid;
	}
	if(judge(r))print(r);
	else print(l);
	return 0; 
}
