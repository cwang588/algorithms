#include<bits/stdc++.h>
using namespace std;
int num[200005];
int main()
{
	int n,cha,tot=0;
	cin>>n>>cha;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	sort(num+1,num+n+1);
	int l=1,r=n/2+1;
	while(l<=n/2&&r<=n)
	{
		if(num[r]-num[l]>=cha)
		{
			++tot;
			++r;
			++l;
			continue;
		}
		else 
			r++;
	}
	cout<<tot;
	return 0;
}
