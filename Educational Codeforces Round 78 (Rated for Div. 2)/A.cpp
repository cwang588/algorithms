#include<bits/stdc++.h>
using namespace std;
char s[105],p[105];
int num[35],numt[34];
bool judge(int l,int r)
{
	memset(numt,0,sizeof(numt));
	for(int i=l;i<=r;++i)++numt[s[i]-'a'+1];
	for(int i=1;i<=26;++i)if(num[i]!=numt[i])return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(s,0,sizeof(s));
		memset(p,0,sizeof(p));
		memset(num,0,sizeof(num));
		cin>>(p+1);
		cin>>(s+1);
		int n=strlen(s+1),m=strlen(p+1);
		for(int i=1;i<=m;++i)++num[p[i]-'a'+1];
		bool ky=false;
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				if(judge(i,j))
				{
					ky=true;
					break;
				}
		if(ky)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
