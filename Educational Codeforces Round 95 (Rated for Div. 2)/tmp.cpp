#include<bits/stdc++.h>
using namespace std;
char s[100005];
int x[100005],y[100005],t[100005],Min[100005];
int main()
{
	cin>>(s+1);
	int n=strlen(s+1);
	Min[0]=2147483647;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')
		{
			x[i]=x[i-1]+1;
			y[i]=y[i-1];
		}
		else
		{
			x[i]=x[i-1];
			y[i]=y[i-1]+1;
		}
		t[i]=x[i]-y[i];
		Min[i]=min(Min[i-1],t[i]);
	}
	int ans=-2147483647;
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,t[i]-Min[i-1]);
		ans=max(ans,t[i]);
	}
	cout<<ans<<"\n";
	return 0;	
}
