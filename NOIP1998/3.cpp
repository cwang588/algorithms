#include<cstdio>
using namespace std;
int A[20]={0,}
int main()
{
	int a,n,m,x;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	f[1]=f[2]=1;
	for(int i=3;i<=20;++i)
		f[i]=f[i-1]+f[i-2];
	int t=(m-a*f[n-2])/f[n-1];
	printf("%d",a*f[x-2]+t*f[x-1]);	
}
