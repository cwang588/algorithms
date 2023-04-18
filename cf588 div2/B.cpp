#include<bits/stdc++.h>
using namespace std;
char s[200005];
int main()
{
	int n,k;
	cin>>n>>k;
	cin>>(s+1);
	if(!k)return !printf("%s\n",s+1);
	if(strlen(s+1)==1)return !printf("0\n");
	int tot=0;
	if(s[1]!='1')
	{
		++tot;
		s[1]='1';
	}
	for(int i=2;i<=n;++i)
	{
		if(tot==k)break;
		if(s[i]-'0')
		{
			s[i]='0';
			++tot;
		}
	}
	printf("%s\n",s+1);
	return 0;
}
