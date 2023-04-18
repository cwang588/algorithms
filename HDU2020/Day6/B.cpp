#include<bits/stdc++.h>
using namespace std;
char s[105];
int main()
{
	ios::sync_with_stdio(false);	
	while(cin>>(s+1))
	{
		int n=strlen(s+1);
		bool you=false;
		for(int i=2;i<=16;++i)
		{
			bool ky=true,dh=false;
			int fh=0;
			long long a=0,b=0,c=0;
			for(int j=1;j<=n;++j)
			{
				if(s[j]>='0'&&s[j]<='9')
				{
					int now=s[j]-'0';
					if(now>=i)
					{
						ky=false;
						break;
					}
					if(!fh)a=a*i+now;
					else
					{
						if(!dh)b=b*i+now;
						else c=c*i+now;
					}
				}
				else if(s[j]=='+')fh=1;
				else if(s[j]=='-')fh=2;
				else if(s[j]=='*')fh=3;
				else if(s[j]=='/')fh=4;
				else if(s[j]=='=')dh=true;
				else
				{
					int now=s[j]-'A'+10;
					if(now>=i)
					{
						ky=false;
						break;
					}
					if(!fh)a=a*i+now;
					else
					{
						if(!dh)b=b*i+now;
						else c=c*i+now;
					}
				}
			}
			if(fh==4&&b*c!=a)ky=false;
			if(fh==1&&a+b!=c)ky=false;
			if(fh==2&&a-b!=c)ky=false;
			if(fh==3&&a*b!=c)ky=false;
			if(ky)
			{
				printf("%d\n",i);
				you=true;
				break;
			}
		}
		if(!you)printf("-1\n");
	}
	return 0;
}
