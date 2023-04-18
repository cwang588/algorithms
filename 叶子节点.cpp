#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
char a[N];
int main()
{
	cin>>a+1;
	int l=strlen(a+1);
	a[l]=' ';
	--l;
	int cnt=0;
	for(int i=1;i<=l;++i)
	{
		if(a[i]!='@'&&(i*2>l||a[i*2]=='@')&&(i*2+1>l||a[i*2+1]=='@'))
		{
			++cnt;
			cout<<a[i]<<' ';
		}
	}
	printf("\n%d",cnt); 
	return 0;
}
