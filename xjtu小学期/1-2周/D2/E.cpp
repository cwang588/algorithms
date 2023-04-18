#include<bits/stdc++.h>
using namespace std;
char t[100005],zhan[100005];
int tong[35],wb;
int main()
{
	cin>>(t+1);
	int l=strlen(t+1),now=1;
	for(int i=1;i<=l;++i)
		++tong[t[i]-'a'+1];
	for(int i=1;i<=l;++i)
	{
		if(now>l)
		{
			printf("%c",zhan[wb]);
			--wb;
			continue;
		}
		int m;
		for(int j=1;j<=26;++j)
			if(tong[j])
			{
				m=j;
				break;
			}
		if(m-1+'a'>=zhan[wb]&&wb)
		{
			printf("%c",zhan[wb]);
			--wb;
			continue;
		}
		while(now<=l&&t[now]!=(char)(m-1+'a'))
		{
			++wb;
			zhan[wb]=t[now];
			--tong[t[now]-'a'+1];
			++now;
		}
		if(now>l)
		{
			printf("%c",t[now]);
			--tong[t[now]-'a'+1];
			--now;
			continue;
		}
		printf("%c",t[now]);
		--tong[t[now]-'a'+1];
		++now;
	}
	return 0;
}
