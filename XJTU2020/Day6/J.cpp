#include<bits/stdc++.h>
using namespace std;
char s[15][10005];
int a[15];
bool judge()
{
	for(int i=1;i<=5;++i)
	{
		int t1=s[i][0]-'A'+1,t2=s[i][2]-'A'+1;
		int p1,p2;
		for(int j=1;j<=5;++j)
		{
			if(a[j]==t1)p1=j;
			if(a[j]==t2)p2=j;
		}
		if((p1<p2&&s[i][1]=='>')||(p1>p2&&s[i][1]=='<'))return false;
	}
	return true;
}
int main()
{
	for(int i=1;i<=5;++i)cin>>s[i];
	for(int i=1;i<=5;++i)a[i]=i;
	if(judge())
	{
		for(int i=1;i<=5;++i)printf("%c",'A'+a[i]-1);
		return !printf("\n");
	}
	while(next_permutation(a+1,a+6))
	{
		if(judge())
		{
			for(int i=1;i<=5;++i)printf("%c",'A'+a[i]-1);
			return !printf("\n");
		}
	}
	printf("impossible\n");
	return 0;
}
