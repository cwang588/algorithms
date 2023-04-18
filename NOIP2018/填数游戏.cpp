#include<cstdio>
#include<algorithm>
using namespace std;
int db[10][10]=
{
	{},{0,2},{0,0,12},{0,0,0,112,336},{0,0,0,0,912,2688},{0,0,0,0,0,7136,21312},{0,0,0,0,0,0,56768,170112},{0,0,0,0,0,0,0,453504,1360128},{0,0,0,0,0,0,0,0,3626752,10879488}
};
const int M=1e9+7;
long long ksm(int a,int b)
{
	if(b==0)
		return 1;
	if(b==1)
		return a;
	long long ans=ksm(a,b/2);
	if(b%2)
		return ((ans*ans%M)*a)%M;
	return ans*ans%M;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)
		swap(n,m);
	if(n==1)
		printf("%lld",ksm(2,m));
	else if(n==2)
		printf("%lld",4*ksm(3,m-1)%M);
	else if(m-n<=1)
		printf("%d",db[n][m]);
	else
		printf("%lld",(db[n][n+1]*(ksm(3,m-n-1)%M))%M);
	return 0;
}
