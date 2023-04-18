#include<cstdio>
#include<iostream>
using namespace std;
long long even[100005],odd[100005];
int main()
{
	long long n,tot=0,p=0,q=0;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		long long t;
		cin>>t;
		if(i%2)
			odd[++p]=odd[p-1]+t;
		else
			even[++q]=even[q-1]+t;
	}
	for(int i=1;i<=p;++i)
		if(odd[i-1]+even[q]-even[i-1]==even[i-1]+odd[p]-odd[i])
			++tot;
	for(int i=1;i<=q;++i)
		if(odd[i]+even[q]-even[i]==even[i-1]+odd[p]-odd[i])
			++tot;
	printf("%I64d",tot);	
	return 0;
}
