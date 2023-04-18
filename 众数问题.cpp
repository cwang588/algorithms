#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int getid(int x)
{
	return lower_bound(v.begin(),v.end(),x)-v.begin()+1; 
}
int s[1000005],num[1000005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&s[i]);
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;++i)++num[getid(s[i])];
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i)
	{
		if(num[i]>ans2)
		{
			ans1=v[i-1];
			ans2=num[i];
		}
	}
	printf("%d\n%d\n",ans1,ans2);	 
	return 0;
}
