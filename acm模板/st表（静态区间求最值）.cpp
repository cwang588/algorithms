#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int f[100005][25];
inline int read()
{
    int X=0,w=1; char ch=0;
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}
int main()
{
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;++i)
		f[i][0]=read();
	for(int j=1;j<=20;++j)
		for(int i=1;i+(1<<j)<=n+1;++i)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=m;++i)
	{
		int l,r;
		l=read();
		r=read();
		int k=log2(r-l+1);
		printf("%d\n",max(f[l][k],f[r-(1<<k)+1][k]));
	}
	return 0;
}
