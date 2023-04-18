#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int l=1,r=n,now=0,ans=0;
	while(l<=r)
	{
		if(a[l]>now&&a[r]>now)
		{
			++ans;
			if(a[l]<a[r])
			{
				now=a[l++];
				b[ans]='L';
			}
			else
			{
				now=a[r--];
				b[ans]='R';
			}
		}
		else if(a[l]<=now&&a[r]<=now)
		{
			printf("%d\n",ans);
			for(int i=1;i<=ans;++i)
				cout<<b[i];
			return 0;
		}
		else
		{
			if(a[l]<=now)
			{
				for(int i=r;i>=l;--i)
				{
					if(a[i]<=now)
					{
						printf("%d\n",ans);
						for(int i=1;i<=ans;++i)
							cout<<b[i];
						return 0;
					}
					now=a[i];
					++ans;
					b[ans]='R';
				}
			}
			else
			{
				for(int i=l;i<=r;++i)
				{
					if(a[i]<=now)
					{
						printf("%d\n",ans);
						for(int i=1;i<=ans;++i)
							cout<<b[i];
						return 0;
					}
					now=a[i];
					++ans;
					b[ans]='L';
				}
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;++i)
		cout<<b[i];	
	return 0;
}
