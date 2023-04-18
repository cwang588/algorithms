#include<bits/stdc++.h>
using namespace std;
struct num
{
	int sum;
}even[200005],odd[200005];
int num1,num2;
bool jo[200005];
bool cmp(num a,num b)
{
	return a.sum<b.sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		int t;
		scanf("%d",&t);
		if(t%2)
		{
			odd[++num2].sum=t;
			jo[i]=true;
		}
		else
			even[++num1].sum=t;		
	}
	sort(odd+1,odd+1+num2,cmp);
	sort(even+1,even+1+num1,cmp);
	int now1=0,now2=0;
	for(int i=1;i<=n;++i)
	{
		if(jo[i])
			printf("%d ",odd[++now1].sum);
		else
			printf("%d ",even[++now2].sum);
	}
	return 0;
}
