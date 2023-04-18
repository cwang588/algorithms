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
			else if(a[l]>a[r])
			{
				now=a[r--];
				b[ans]='R';
			}
			else
			{
				int num1=1,num2=1,now1=now,now2=now;
				for(int i=l;i<=r;++i)
				{
					if(a[i]<=now1)
						break;
					now1=a[i];
					++num1;
				}
				for(int i=r;i>=l;--i)
				{
					if(a[i]<=now2)
						break;
					now2=a[i];
					++num2;
				}
				if(num1>=num2)
				{
					printf("%d\n",ans+num1-2);
					for(int i=1;i<ans;++i)
						cout<<b[i];
					for(int i=1;i<num1;++i)
						cout<<'L';
				}
				else
				{
					printf("%d\n",ans+num2-2);
					for(int i=1;i<ans;++i)
						cout<<b[i];
					for(int i=1;i<num2;++i)
						cout<<'R';
				}			
				return 0;
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
