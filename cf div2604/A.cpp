#include<bits/stdc++.h>
using namespace std;
char a[100005];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cin>>(a+1);
		int l=strlen(a+1);
		bool ky=true;
		for(int i=1;i<=l;++i)
		{
			if(a[i]=='?')
			{
				if(i==1)
				{
					if(a[i+1]!='a')a[i]='a';
					else a[i]='b';
				}
				else if(i==l)
				{
					if(a[i-1]!='a')a[i]='a';
					else a[i]='b';
				}
				else
				{
					if(a[i-1]==a[i+1])
					{
						if(a[i-1]=='a')a[i]='b';
						else a[i]='a';
					}
					else
					{
						if(a[i-1]!='a'&&a[i+1]!='a')a[i]='a';
						if(a[i-1]!='b'&&a[i+1]!='b')a[i]='b';
						if(a[i-1]!='c'&&a[i+1]!='c')a[i]='c';
					}
				}
			}
			else
			{
				if(a[i-1]==a[i]||a[i+1]==a[i])
				{
					//cout<<"-1"<<endl;
					ky=false;
					break;
				}
			}
		}
		if(!ky)cout<<"-1"<<endl;
		else cout<<(a+1)<<endl;
	}
	return 0;
}
