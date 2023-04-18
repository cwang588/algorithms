#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[N];
int h1=1,h2=1,tot=0,n;
int getmin()
{
	if(!h2||h2>tot)
	{
		h1++;
		return a[h1-1];
	}
	if(h1>n)
	{
		h2++;
		return b[h2-1];
	}
	if(a[h1]<b[h2])
	{
		h1++;
		return a[h1-1];
	}
	h2++;
	return b[h2-1];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<n;++i)
	{
		int t=0;
		t+=getmin();
		t+=getmin();
		ans+=t;
		b[++tot]=t;
	}
	printf("%d",ans);
	return 0;
}
