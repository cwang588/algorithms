#include<bits/stdc++.h>
using namespace std;
int a[100005];
int calc(int l,int r)
{
	int re=0;
	for(int i=l;i<=r;++i)
		re^=a[i];
	return re;
}
int main()
{
//	int t;
//	scanf("%d",&t); 
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
		for(int k=i+1;k<=n;++k)
			for(int j=i+1;j<=k;++j)
				if(calc(i,j-1)==calc(j,k))
				{
					cout<<i<<' '<<j<<' '<<k<<endl;
					++ans;
				}
	cout<<ans;
	return 0;
} 
