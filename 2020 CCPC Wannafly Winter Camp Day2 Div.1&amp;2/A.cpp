#include<bits/stdc++.h>
using namespace std;
char t[1000005];
long long sum[1000005],f[1000005];
int main()
{
	cin>>(t+1);
	int n=strlen(t+1);
	for(int i=1;i<=n;++i)	
	{
		sum[i]=sum[i-1];
		if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u'||t[i]=='y')++sum[i];
	}
	double tot=0;
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1]+sum[n-i+1]-sum[i-1];
		tot+=(double)f[i]/(double)i;
	}
	double ans=(double)(2.0*tot)/(double)(n*(n+1));
	printf("%.8lf\n",ans);
	return 0;
}
