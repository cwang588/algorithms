#include<bits/stdc++.h>
using namespace std;
struct human
{
	string name;
	double num;
}a[505],b[505];
bool usd1[505],usd2[505];
bool cmp(human x,human y)
{
	return x.num<y.num;
}
int main()
{
	int n;	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].name>>a[i].num>>b[i].num;
		b[i].name=a[i].name;
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	double ans=999999.0;
	int sum1,sum2,sum3,sum4;
	for(int i=1;i<=4;++i)
		for(int j=1;j<=2;++j)
			for(int k=j+1;k<=3;++k)
				for(int o=k+1;o<=4;++o)
				{
					if(a[i].name!=b[j].name&&a[i].name!=b[k].name&&a[i].name!=b[o].name)
					{
						if(ans>a[i].num+b[j].num+b[k].num+b[o].num)
						{
							ans=a[i].num+b[j].num+b[k].num+b[o].num;
							sum1=i;
							sum2=j;
							sum3=k;
							sum4=o;
						}
					}
				}			
	cout<<ans<<endl<<a[sum1].name<<endl<<b[sum2].name<<endl<<b[sum3].name<<endl<<b[sum4].name<<endl;
	return 0;
}
