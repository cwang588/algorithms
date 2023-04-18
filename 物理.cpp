#include<bits/stdc++.h>
using namespace std;
double data[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		cin>>data[i];
	double ans1=0;
	for(int i=1;i<=n;++i)
		ans1+=data[i];
	printf("平均值%lf\n",ans1/(double)n);
	double ans2=0;
	for(int i=1;i<=n;++i)
		ans2+=(ans1/(double)n-data[i])*(ans1/(double)n-data[i]);
	printf("标准偏差%lf\n",sqrt(ans2/(double)(n-1)));	
	printf("平均值的标准偏差%lf\n",sqrt(ans2/(double)(n-1))/sqrt(n*1.0));	
}
	
