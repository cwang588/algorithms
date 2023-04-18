#include<cstdio>
#include<algorithm>
using namespace std;
long long mian[100005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int Num;
	long long Xx1,Yy1,Xx2,Yy2,Xx3,Yy3;
	scanf("%d%lld%lld%lld%lld%lld%lld",&Num,&Xx1,&Yy1,&Xx2,&Yy2,&Xx3,&Yy3);
	mian[1]=Xx1*Yy2+Xx2*Yy3+Xx3*Yy1-Xx1*Yy3-Xx2*Yy1-Xx3*Yy2;
	int r=1,tt=Num;
	for(int i=2;i<=n;++i)
	{
		int num;
		long long xx1,yy1,xx2,yy2,xx3,yy3;
		scanf("%d%lld%lld%lld%lld%lld%lld",&num,&xx1,&yy1,&xx2,&yy2,&xx3,&yy3);
		mian[i]=xx1*yy2+xx2*yy3+xx3*yy1-xx1*yy3-xx2*yy1-xx3*yy2;
		if(num>tt)
			++r;
	}
	sort(mian+1,mian+n+1,cmp);
	printf("%lld",mian[r]);
	return 0;
}
