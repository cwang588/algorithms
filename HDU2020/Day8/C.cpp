#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{ 
		long long a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		long long xx1=c-a,yy1=d-b,xx2=e-a,yy2=f-b;
		long long tmp=xx1*yy2-xx2*yy1;
		if(tmp<0)printf("Clockwise\n");
		else printf("Counterclockwise\n");
	}
	return 0;
}
