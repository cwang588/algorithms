#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[61][21],f[500005];
int main()
{
	int s,d,m;
	scanf("%d%d%d",&s,&d,&m);
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=d;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}//以上不需要解释
	for(int k=2;k<=d;k++)
	{
		memset(f,0,sizeof(f));
		int maxx=0;
		for(int i=1;i<=s;i++)
		{
			for(int j=a[i][k-1];j<=m;j++)//每次循环到前一天当前位置的股票交易价格。
			{
				f[j]=fmax(f[j],f[j-a[i][k-1]]+a[i][k]-a[i][k-1]);//第一种情况是不买，第二种就是买：要价格减去买入所花的钱再加上今天和昨天的价格差，因为如果不卖出相当于卖出再买入
				maxx=fmax(f[j],maxx);//取出一天股票的最大值
			}
		}
		m+=maxx;//累加收益
	}
	printf("%d",m);
	return 0;
}

