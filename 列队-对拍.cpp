#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
long long a[10005][10005];
int b[100005];
int nt[100005];
int n,m,q;
void pianfen1()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=(i-1)*m+j;
	for(int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int tmp=a[x][y];
		for(int j=y;j<=m;++j)
			a[x][j]=a[x][j+1];
		for(int j=x;j<n;++j)
			a[j][m]=a[j+1][m];
		a[n][m]=tmp;
		printf("%d\n",tmp);
	}	
}
void pianfen2()
{
	for(int i=1;i<=m;++i)
		b[i]=i;
	for(int i=1;i<=q;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int tmp=b[y];
		for(int j=y;j<=n;++j)
			b[j]=b[j+1];
		b[m]=tmp;
		printf("%d\n",tmp);
	}
}
inline int read() 
{
    char ch=getchar();
	int x=0,f=1;
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    } 
	while('0'<=ch&&ch<='9') 
	{
        x=x*10+ch-'0';
        ch=getchar();
    } 
	return x*f;
}

int main()
{
	freopen("data.txt","r",stdin);
//	freopen("phalanx.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	if(q<=500)	
		pianfen1();
	else if(n==1)
		pianfen2();
	return 0;
}