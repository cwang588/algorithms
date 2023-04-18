#include<bits/stdc++.h>
using namespace std;
int num[28];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		char t;
		cin>>t;
		++num[t-'a'];
	}
	int Max=0;
	for(int i=0;i<26;++i)
		Max=Max<num[i]?num[i]:Max;
	printf("%d",n-Max);
	return 0;
}
