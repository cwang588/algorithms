#include<bits/stdc++.h>
using namespace std;
int a[15],dp1[15],dp2[15];
int n;
int calc1()
{
	for(int i=1;i<=n;++i)dp1[i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(a[i]>a[j])
				dp1[i]=max(dp1[i],dp1[j]+1);
	int re=0;
	for(int i=1;i<=n;++i)re=max(re,dp1[i]);
	return re;
}
int calc2()
{
	for(int i=1;i<=n;++i)dp2[i]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			if(a[i]<a[j])
				dp2[i]=max(dp2[i],dp2[j]+1);
	int re=0;
	for(int i=1;i<=n;++i)re=max(re,dp2[i]);
	return re;
}
void print()
{
	for(int i=1;i<=n;++i)printf("%d ",a[i]);
	printf(":\n");
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)a[i]=i;
	print();
	cout<<calc1()<<' '<<calc2()<<endl;
	while(next_permutation(a+1,a+1+n))print(),cout<<calc1()<<' '<<calc2()<<endl;
	return 0;
}
