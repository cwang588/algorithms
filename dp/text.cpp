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
	}//���ϲ���Ҫ����
	for(int k=2;k<=d;k++)
	{
		memset(f,0,sizeof(f));
		int maxx=0;
		for(int i=1;i<=s;i++)
		{
			for(int j=a[i][k-1];j<=m;j++)//ÿ��ѭ����ǰһ�쵱ǰλ�õĹ�Ʊ���׼۸�
			{
				f[j]=fmax(f[j],f[j-a[i][k-1]]+a[i][k]-a[i][k-1]);//��һ������ǲ��򣬵ڶ��־�����Ҫ�۸��ȥ����������Ǯ�ټ��Ͻ��������ļ۸���Ϊ����������൱������������
				maxx=fmax(f[j],maxx);//ȡ��һ���Ʊ�����ֵ
			}
		}
		m+=maxx;//�ۼ�����
	}
	printf("%d",m);
	return 0;
}

