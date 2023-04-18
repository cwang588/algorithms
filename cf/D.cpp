#include<cstdio>
#include<algorithm> 
using namespace std;
struct tong
{
	int sum,id;
}t[200005];
bool cmp(tong a,tong b)
{
	return a.sum>b.sum;
}
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int M=0;
	for(int i=1;i<=n;++i)
	{
		int a;
		scanf("%d",&a);
		++t[a].sum;
		if(M<a)
			M=a;
	}
	for(int i=1;i<=M;++i)
		t[i].id=i;
	sort(t+1,t+1+M,cmp);
	int num=0,ans=t[1].sum;
	for(int i=1;i<=n;++i)
	{
		int now=gcd(t[i].sum,ans);
		num*=ans/now;
		num+=t[i].sum/now;
		ans=now;
		if(num>=k)
		{
			int tot=0,j=1;
			while(tot<k)
			{
				for(int o=1;o<=t[j].sum/ans&&tot<k;++o,++tot)
					printf("%d ",t[j].id);
				++j;
			}
			return 0;
		}
	}
	return 0;
}
