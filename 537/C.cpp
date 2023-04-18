#include<cstdio>
#include<iostream>
using namespace std;
long long mo[3],f[200005][3];
const long long m=1e9+7;
int main()
{
	int n;
	long long l,r;
	scanf("%d",&n);
	cin>>l>>r;
	mo[0]=mo[1]=mo[2]=(r-l)/3;
	for(int i=l+(r-l)/3*3;i<=r;++i)
		++mo[i%3];
	for(int i=0;i<3;++i)
		f[1][i]=mo[i];
	f[0][0]=1;
	for(int i=2;i<=n;++i)
	{
		f[i][0]=(mo[0]*f[i-1][0]+mo[1]*f[i-1][2]+mo[2]*f[i-1][1])%m;
		f[i][1]=(mo[0]*f[i-1][1]+mo[1]*f[i-1][0]+mo[2]*f[i-1][2])%m;
		f[i][2]=(mo[0]*f[i-1][2]+mo[1]*f[i-1][1]+mo[2]*f[i-1][0])%m;
	}
	cout<<f[n][0];
	return 0;
}
