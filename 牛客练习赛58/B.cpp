#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int main()
{
	int ans=0;
	cin>>(s+1);
	int n=strlen(s+1);
	bool zero=false,one=false;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='0')zero=true;
		else one=true;
		if(one&&zero)
		{
			++ans;
			one=false;
			zero=false;
		}
	}
	printf("%d\n",ans);
	return 0;
}
