#include<cstring>
#include<cstdio>
#include<cctype>
using namespace std;
int price[55][15];
int dp[500050];
inline int read()
{
    char ch=getchar();
	int x=0,flag=0;
    while(!isdigit(ch)){ if (ch == '-') flag = 1; ch = getchar(); }
    while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
    return flag ? -x : x;
}
int main()
{
	int s,d,m;
	s=read();
	d=read();
	m=read();
	int now=m;
	for(int i=1;i<=s;++i)
		for(int j=1;j<=d;++j)
			price[i][j]=read();
	for(int i=1;i<d;++i)
	{
		int Max=0;
		memset(dp,0,sizeof(dp));
		for(int j=1;j<=s;++j)
			for(int k=price[j][i];k<=now;++k)
			{
				if(dp[k]<dp[k-price[j][i]]+price[j][i+1]-price[j][i])
					dp[k]=dp[k-price[j][i]]+price[j][i+1]-price[j][i];
				if(Max<dp[k])
					Max=dp[k];
			}
		now+=Max;
	}
	printf("%d",now);
	return 0;
}
