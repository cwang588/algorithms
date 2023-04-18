#include<bits/stdc++.h>
using namespace std;
int tx[4]={0,0,1,-1},ty[4]={1,-1,0,0};
int main()
{
	srand((unsigned)time(0));
	int n,t;
	cin>>n>>t;
	long long tot=0;
	while(t--)
	{
		long long x=0,y=0;
		for(int i=1;i<=n;++i)
		{
			int ran=rand()%4;
			x+=tx[ran],y+=ty[ran];
		}
		tot+=(x*x+y*y);
	}
	cout<<tot;
	return 0; 
}
