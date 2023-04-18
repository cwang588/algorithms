#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,A,B,C,a,b,c,x,y,z,ans;
	ans=999999999;
	cin>>n;
	cin>>A>>a;
	cin>>B>>b;
	cin>>C>>c;
	if(n%A==0)
		x=n/A*a;
	else
		x=(n/A+1)*a;
	if(n%B==0)
		y=n/B*b;
	else
		y=(n/B+1)*b;
	if(n%C==0)
		z=n/C*c;
	else
		z=(n/C+1)*c;
	if(ans>x)
		ans=x;
	if(ans>y)
		ans=y;
	if(ans>z)
		ans=z;	
	cout<<ans;		
	return 0;
}

